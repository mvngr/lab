using System; 
using System.Diagnostics; 
using System.Windows; 
using System.Windows.Input; 
using System.Windows.Media.Media3D; 
using System.Windows.Markup;

using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Media;

//Пирамидка - Pyramid 
//тор - DrawTor 
//трекбол - Trackball
//направленный свет - PointLight

namespace _3DTools
{

    public class Trackball
    {
        private FrameworkElement _eventSource;
        private Point _previousPosition2D;
        private Vector3D _previousPosition3D = new Vector3D(0, 0, 1);

        private Transform3DGroup _transform;
        private ScaleTransform3D _scale = new ScaleTransform3D();
        private AxisAngleRotation3D _rotation = new AxisAngleRotation3D();

        public Trackball()
        {
            _transform = new Transform3DGroup();
            _transform.Children.Add(_scale);
            _transform.Children.Add(new RotateTransform3D(_rotation));
        }
        public Transform3D Transform
        {
            get { return _transform; }
        }

        #region Event Handling 
        public FrameworkElement EventSource
        {
            get { return _eventSource; }

            set
            {
                if (_eventSource != null)
                {
                    _eventSource.MouseDown -= this.OnMouseDown;
                    _eventSource.MouseUp -= this.OnMouseUp;
                    _eventSource.MouseMove -= this.OnMouseMove;
                }

                _eventSource = value;

                _eventSource.MouseDown += this.OnMouseDown;
                _eventSource.MouseUp += this.OnMouseUp;
                _eventSource.MouseMove += this.OnMouseMove;
            }
        }

        private void OnMouseDown(object sender, MouseEventArgs e)
        {
            Mouse.Capture(EventSource, CaptureMode.Element);
            _previousPosition2D = e.GetPosition(EventSource);
            _previousPosition3D = ProjectToTrackball(
                EventSource.ActualWidth,
                EventSource.ActualHeight,
                _previousPosition2D);
        }

        private void OnMouseUp(object sender, MouseEventArgs e)
        {
            Mouse.Capture(EventSource, CaptureMode.None);
        }

        private void OnMouseMove(object sender, MouseEventArgs e)
        {
            Point currentPosition = e.GetPosition(EventSource);

            if (e.LeftButton == MouseButtonState.Pressed)
            {
                Track(currentPosition);
            }
            else if (e.RightButton == MouseButtonState.Pressed)
            {
                Zoom(currentPosition);
            }

            _previousPosition2D = currentPosition;
        }

        #endregion Event Handling 

        private void Track(Point currentPosition)
        {
            try
            {

                Vector3D currentPosition3D = ProjectToTrackball(
                    EventSource.ActualWidth, EventSource.ActualHeight, currentPosition);

                Vector3D axis = Vector3D.CrossProduct(_previousPosition3D, currentPosition3D);
                double angle = Vector3D.AngleBetween(_previousPosition3D, currentPosition3D);
                Quaternion delta = new Quaternion(axis, -angle);

                AxisAngleRotation3D r = _rotation;
                Quaternion q = new Quaternion(_rotation.Axis, _rotation.Angle);

                q *= delta;

                _rotation.Axis = q.Axis;
                _rotation.Angle = q.Angle;

                _previousPosition3D = currentPosition3D;
            }
            catch(Exception e)
            {
                Debug.WriteLine(e.Message);
            }
        }

        private Vector3D ProjectToTrackball(double width, double height, Point point)
        {
            double x = point.X / (width / 2);     
            double y = point.Y / (height / 2);

            x = x - 1;                           
            y = 1 - y;                          

            double z2 = 1 - x * x - y * y;     
            double z = z2 > 0 ? Math.Sqrt(z2) : 0;

            return new Vector3D(x, y, z);
        }

        private void Zoom(Point currentPosition)
        {
            double yDelta = currentPosition.Y - _previousPosition2D.Y;

            double scale = Math.Exp(yDelta / 100); 

            _scale.ScaleX *= scale;
            _scale.ScaleY *= scale;
            _scale.ScaleZ *= scale;
        }
    }

    public class Simple3DSceneInCode : Window
    {
        PerspectiveCamera cam;


        [STAThread]
        public static void Main()
        {
            Application app = new Application();
            app.Run(new Simple3DSceneInCode());
        }

        public Simple3DSceneInCode()
        {
            Title = "Simple 3D Scene in Code";
            this.Width = 900;
            this.Height = 600;

            DockPanel dock = new DockPanel();
            Content = dock;

            ScrollBar scroll = new ScrollBar();
            scroll.Orientation = Orientation.Horizontal;
            scroll.Value = -2;
            scroll.Minimum = -2;
            scroll.Maximum = 2;
            scroll.ValueChanged += ScrollBarOnValueChanged;
            dock.Children.Add(scroll);
            DockPanel.SetDock(scroll, Dock.Bottom);

            
            Viewport3D viewport = new Viewport3D();
            dock.Children.Add(viewport);

            MeshGeometry3D mesh = new MeshGeometry3D();
            mesh.Positions.Add(new Point3D(0, 0, 0));
            mesh.Positions.Add(new Point3D(0, 1, -1));
            mesh.Positions.Add(new Point3D(0, 0, -2));
            mesh.TriangleIndices = new Int32Collection { 0, 1, 2 };

            DrawTor(new Point3D(0, 0, 0), 2, 1, 50, 25, Colors.LightGreen, ref viewport);

            
            GeometryModel3D geomod = new GeometryModel3D();
            //geomod.Geometry = Pyramid(2.0, 2.0);//Konus(3.0, 1.0, 9);
            geomod.Material = new DiffuseMaterial(new LinearGradientBrush(Colors.DarkBlue, Colors.LightBlue, 90.0));
            geomod.BackMaterial = new DiffuseMaterial(Brushes.Red);
            
            ModelVisual3D modvis = new ModelVisual3D();
            //modvis.Content = geomod;
            viewport.Children.Add(modvis);

            modvis = new ModelVisual3D();
            modvis.Content = new PointLight
            {
                Position = new Point3D(0.0, 10.0, 0.0),
                Color = Colors.White,
                ConstantAttenuation = 1.0,
                LinearAttenuation = 0.0,
                QuadraticAttenuation = 0.0
            };
            viewport.Children.Add(modvis);

            // Создаем камеру
            cam = new PerspectiveCamera(new Point3D(0, 0, 10),
                            new Vector3D(0, 0, -1), new Vector3D(0, 1, 0), 45);
            viewport.Camera = cam;


            Trackball track = new Trackball();
            track.EventSource = viewport;
            viewport.Camera.Transform = track.Transform;
        }
        void ScrollBarOnValueChanged(object sender,
                            RoutedPropertyChangedEventArgs<double> args)
        {
            cam.Position = new Point3D(args.NewValue, 0, 10);
        }

        MeshGeometry3D Konus(double h, double r, int n)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();

            double fi, delta = 2 * Math.PI / n;
            double r1 = 0.66 * r, h1 = 0.66 * h;
            Point3D point;
            for (int k = 0; k <= n; k++)
            {
                fi = delta * k;
                double x = r * Math.Cos(fi);
                double z = r * Math.Sin(fi);
                point = new Point3D(x, 0.0, z);
                mesh.Positions.Add(point);

                double x1 = r1 * Math.Cos(fi);
                double z1 = r1 * Math.Sin(fi);
                point = new Point3D(x1, h1, z1);
                mesh.Positions.Add(point);
            }

            for (int k = 0; k < n; k += 2)
            {
                mesh.TriangleIndices.Add(k);
                mesh.TriangleIndices.Add(k + 1);
                mesh.TriangleIndices.Add(k + 2);
                mesh.TriangleIndices.Add(k + 1);
                mesh.TriangleIndices.Add(k + 3);
                mesh.TriangleIndices.Add(k + 2);
            }

            return mesh;
        }

        MeshGeometry3D Pyramid(double h, double width)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();

            Point3D point;
            for (int i = 0; i < 2; i++) //Ставим нижние 4 точки
            {
                point = new Point3D(width / 2, 0, width / 2);
                mesh.Positions.Add(point);
                point = new Point3D(-width / 2, 0, -width / 2);
                mesh.Positions.Add(point);
            }
            mesh.Positions.Add(new Point3D(0, h, 0)); //Ставим верхнюю точку

            //Начинаем соединять две нижние точки и одну верхнюю
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(4);
            //--
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(2);
            mesh.TriangleIndices.Add(4);
            //--
            mesh.TriangleIndices.Add(2);
            mesh.TriangleIndices.Add(3);
            mesh.TriangleIndices.Add(4);
            //--
            mesh.TriangleIndices.Add(3);
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(4);
            //--
            //Теперь нижнюю часть
            ////--
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(2);
            //--
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(2);
            mesh.TriangleIndices.Add(3);

            return mesh;
        }

        public Point3D getPositionTor(double R, double r, double A, double B)
        {

            double sinB = Math.Sin(B * Math.PI / 180);
            double cosB = Math.Cos(B * Math.PI / 180);
            double sinA = Math.Sin(A * Math.PI / 180);
            double cosA = Math.Cos(A * Math.PI / 180);

            Point3D point = new Point3D();
            point.X = (R + r * cosA) * cosB;
            point.Y = r * sinA;
            point.Z = -(R + r * cosA) * sinB;

            return point;
        }

        public static void drawTriangle(
            Point3D p0, Point3D p1, Point3D p2, Color color, Viewport3D viewport)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();

            mesh.Positions.Add(p0);
            mesh.Positions.Add(p1);
            mesh.Positions.Add(p2);

            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(2);

            SolidColorBrush brush = new SolidColorBrush();
            brush.Color = color;
            Material material = new DiffuseMaterial(brush);

            GeometryModel3D geometry = new GeometryModel3D(mesh, material);
            ModelUIElement3D model = new ModelUIElement3D();
            model.Model = geometry;

            viewport.Children.Add(model);
        }

        public void DrawTor(Point3D center, double R, double r, int N, int n, Color color, ref Viewport3D mainViewport)
        {
            if (n < 2 || N < 2)
            {
                return;
            }

            Model3DGroup tor = new Model3DGroup();
            Point3D[,] points = new Point3D[N, n];

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    points[i, j] = getPositionTor(R, r, i * 360 / (N - 1), j * 360 / (n - 1));
                    points[i, j] += (Vector3D)center;
                }
            }

            Point3D[] p = new Point3D[4];
            for (int i = 0; i < N - 1; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    p[0] = points[i, j];
                    p[1] = points[i + 1, j];
                    p[2] = points[i + 1, j + 1];
                    p[3] = points[i, j + 1];
                    drawTriangle(p[0], p[1], p[2], color, mainViewport);
                    drawTriangle(p[2], p[3], p[0], color, mainViewport);

                }
            }
        }


    }
}
