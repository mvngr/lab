using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Ink;
using System.IO;
using System.Xml;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            
        }

        private const String filename = "inkstrokes.isf";

        public void ClearCanvas(object sender, RoutedEventArgs e)
        {
            myCanvas.Strokes.Clear();
            statusText.Content = "Successfully cleared";
        }

        public void OpenCanvas(object sender, RoutedEventArgs e)
        {
            FileStream fs = new FileStream(filename, FileMode.Open, FileAccess.Read);
            StrokeCollection strokes = new StrokeCollection(fs);
            myCanvas.Strokes = strokes;
            fs.Close();
            statusText.Content = "Opened from " + filename;
        }

        public void SaveCanvas(object sender, RoutedEventArgs e)
        {
            
            FileStream fs = new FileStream(filename, FileMode.Create);
            myCanvas.Strokes.Save(fs);
            fs.Close();
            statusText.Content = "Saved to " + filename;
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (myCanvas != null)
            {
                if (ToolChooser.SelectedItem == pen)
                {
                    myCanvas.EditingMode = InkCanvasEditingMode.Ink;
                }
                if (ToolChooser.SelectedItem == erase)
                {
                    myCanvas.EditingMode = InkCanvasEditingMode.EraseByPoint;
                }
                if (ToolChooser.SelectedItem == select)
                {
                    myCanvas.EditingMode = InkCanvasEditingMode.Select;
                }
                
            }
        }

        private void ColorChanged(object sender, RoutedEventArgs e)
        {
            var button = (Button)sender;
            myCanvas.DefaultDrawingAttributes.Color = ((SolidColorBrush)button.Background).Color;
        }
    }
}
