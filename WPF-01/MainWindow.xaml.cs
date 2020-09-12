using System;
using System.Diagnostics;
using System.Security.Cryptography;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace Petzold.Simple3DSceneInCode
{
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
            mesh.TriangleIndices = new Int32Collection{ 0, 1, 2 };

            GeometryModel3D geomod = new GeometryModel3D();
            geomod.Geometry = Konus(3.0, 1.0, 9);
            geomod.Material = new DiffuseMaterial(new LinearGradientBrush(Colors.DarkBlue, Colors.LightBlue, 90.0));
            geomod.BackMaterial = new DiffuseMaterial(Brushes.Red);

            ModelVisual3D modvis = new ModelVisual3D();
            modvis.Content = geomod;
            viewport.Children.Add(modvis);

            modvis = new ModelVisual3D();
            modvis.Content = new AmbientLight(Colors.White);
            viewport.Children.Add(modvis);

            // Создаем камеру
            cam = new PerspectiveCamera(new Point3D(0, 0, 5),
                            new Vector3D(0, 0, -1), new Vector3D(0, 1, 0), 45);
            viewport.Camera = cam;
        }
        void ScrollBarOnValueChanged(object sender,
                            RoutedPropertyChangedEventArgs<double> args)
        {
            cam.Position = new Point3D(args.NewValue, 0, 5);
        }

        /*!
         * Препод дал уже готовый код
         */
        MeshGeometry3D Konus(double h, double r, int n)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();

            double fi, delta = 2 * Math.PI / n;
            double r1 = 0.66 * r, h1 = 0.66 * h;
            Point3D point;
            for(int k = 0; k <= n; k++)
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

            for(int k = 0; k < n; k+= 2)
            {
                mesh.TriangleIndices.Add(k);
                mesh.TriangleIndices.Add(k+1);
                mesh.TriangleIndices.Add(k+2);
                mesh.TriangleIndices.Add(k+1);
                mesh.TriangleIndices.Add(k+3);
                mesh.TriangleIndices.Add(k+2);
            }

            return mesh;
        }

        MeshGeometry3D Pyramid(double h, double width)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();

            Point3D point;
            
            point = new Point3D(width / 2, 0, width / 2);
            mesh.Positions.Add(point);
            point = new Point3D(width / 2, 0, -width / 2);
            mesh.Positions.Add(point);
            point = new Point3D(-width / 2, 0, -width / 2);
            mesh.Positions.Add(point);
            point = new Point3D(-width / 2, 0, width / 2);
            mesh.Positions.Add(point);

            mesh.Positions.Add(new Point3D(0, h, 0)); //Ставим верхнюю точку

            foreach (Point3D a in mesh.Positions)
            {
                Debug.WriteLine(a.ToString());
            }
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
    }
}