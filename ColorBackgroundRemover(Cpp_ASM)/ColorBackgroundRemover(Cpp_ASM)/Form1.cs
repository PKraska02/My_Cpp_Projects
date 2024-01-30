using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ColorBackgroundRemover_Cpp_ASM_
{
    public partial class GUI : Form
    {
        private OpenFileDialog openFileDialog1 = new OpenFileDialog();
        //private byte[] imageData; // Dane obrazu
        private int[] xValues;    // Tablica xValues
        private int[] yValues;
        private int power = 0;
        private int pointCounter = 0;
        private bool isPipetteOn = false;
        private int MaxPoints = 32;
        private bool isCutterSelected = false;
        private int selectedIndex;
        private string selectedLanguage;
        private int new_red;
        private int new_green;
        private int new_blue;
        private int threads;
        Color clickedColor;
        [DllImport(@"C:\Users\Piotr\source\repos\My_Cpp_Projects\ColorBackgroundRemover(Cpp_ASM)\ASMColorRemoverLIB\x64\Release\ASMColorRemoverLIB.dll")]
        static extern void ProcessImageASM(float[] pixelValues, float[] adjustpixels);

        //[DllImport(@"C:\Users\Piotr\source\repos\My_Cpp_Projects\ColorBackgroundRemover(Cpp_ASM)\x64\Debug\CPPColorRemoverLIB.dll")]
          [DllImport(@"C:\Users\Piotr\source\repos\My_Cpp_Projects\ColorBackgroundRemover(Cpp_ASM)\x64\Debug\CPPColorRemoverLIB.dll")] 
        static extern void ProcessImageCPP(byte[] imageData, int width, int height, int power, int[] xValues, int[] yValues, int pointcount, int new_red, int new_green, int new_blue, int y1);
        public GUI()
        {
            InitializeComponent();
            //imageData = null; // Tutaj możesz zainicjować dane obrazu
            xValues = new int[32]; // Tutaj możesz zainicjować tablicy xValues
            yValues = new int[32];
            for (int i = 0; i < 32; i++)
            {
                xValues[i] = 0;
                yValues[i] = 0;
            }
            selectedIndex = 0;
            selectedLanguage = "";

            // Dodanie opcji do ComboBoxa
            languageComboBox.Items.Add("C++");
            languageComboBox.Items.Add("ASM");

            // Ustawienie domyślnej opcji
            languageComboBox.SelectedIndex = selectedIndex;
        }

        private void mainPictureBox_Click(object sender, EventArgs e)
        {
            MouseEventArgs me = (MouseEventArgs)e;

            if (isCutterSelected && pointCounter < MaxPoints)
            {
                // Get the clicked point
                Point clickedPoint = me.Location;
                xValues[pointCounter] = clickedPoint.X;
                yValues[pointCounter] = clickedPoint.Y;
                pointCounter++;

                // Use the clickedPoint as needed, for example, display in a MessageBox
                MessageBox.Show($"Clicked point - X: {clickedPoint.X}, Y: {clickedPoint.Y}");
            }
            else
            {
                // Optional: Inform the user that the maximum number of points has been reached
                MessageBox.Show("Maximum number of points reached!");
            }

            // Check if the left mouse button is clicked and the pipette is active
            if (me.Button == MouseButtons.Left && isPipetteOn)
            {
                // Get the clicked point
                isCutterSelected = false;
                Point clickedPoint = me.Location;

                // Get the color of the clicked point
                clickedColor = GetPixelColor(clickedPoint);
                new_red = clickedColor.R;
                new_green = clickedColor.G;
                new_blue = clickedColor.B;

                // Convert the color components to string for display
                string colorInfo = $"R: {clickedColor.R}, G: {clickedColor.G}, B: {clickedColor.B}";

                // Show the color information in a message box
                MessageBox.Show("Pipetted Color: " + colorInfo);

                // Reset the pipette active state to false
                isPipetteOn = false;

                // Update label based on pipette activation state
                pippeteActivationStatus.Text = isPipetteOn ? "Pipette activated" : "Pipette deactivated";
            }

        }
        private Color GetPixelColor(Point point)
        {
            // Assuming mainPictureBox is the PictureBox control
            if (mainPictureBox.Image != null)
            {
                Bitmap bitmap = new Bitmap(mainPictureBox.Image);
                return bitmap.GetPixel(point.X, point.Y);
            }

            return Color.Empty;
        }
        private void mainPanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void pippeteLabel_Click(object sender, EventArgs e)
        {

        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            //Pippete
            isPipetteOn = !isPipetteOn;
            pippeteActivationStatus.Text = isPipetteOn ? "Pipette activated" : "Pipette deactivated";


        }

        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            //decrease power
            power -= 5;
            if (power < 0)
            {
                power = 0;
                toolStripTextBox1.Text = power.ToString();
            }
            toolStripTextBox1.Text = power.ToString();

        }

        private void decreasePowerButton_Click(object sender, EventArgs e)
        {


        }

        private void increasePowerButton_Click(object sender, EventArgs e)
        {
        }

        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            //increase power
            power += 5;
            if (power > 100)
            {
                power = 100;
                toolStripTextBox1.Text = power.ToString();
            }
            toolStripTextBox1.Text = power.ToString();

        }

        private void pippeteActivationStatus_Click(object sender, EventArgs e)
        {

        }

        private void clipperActivationStatus_Click(object sender, EventArgs e)
        {

        }

        private void loadImage_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "Image Files|*.bmp;*.jpg;*.jpeg;*.gif;*.png";
            openFileDialog1.Title = "Select an Image File";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                // Get the selected file name
                string selectedFileName = openFileDialog1.FileName;

                // Display the selected image in the PictureBox
                mainPictureBox.Image = Image.FromFile(selectedFileName);
            }
        }

        private void runButton_Click(object sender, EventArgs e)
        {
            if (int.TryParse(textBox3.Text, out int selectedThreads))
            {
                // Sprawdź, czy liczba wątków jest większa niż zero
                if (selectedThreads > 0 && selectedThreads <= 64)
                {
                    threads = selectedThreads;
                }
                else
                {
                    MessageBox.Show("Liczba wątków musi być większa niż zero.");
                    // Tutaj możesz ewentualnie ustawić domyślną wartość liczby wątków, na przykład 1.
                    textBox3.Text = "1";
                    int.TryParse(textBox3.Text, out selectedThreads);
                    threads = selectedThreads;
                }
            }
            else
            {
                MessageBox.Show("Podana wartość nie jest liczbą całkowitą.");
                // Tutaj możesz ewentualnie ustawić domyślną wartość liczby wątków, na przykład 1.
                textBox3.Text = "1";
                int.TryParse(textBox3.Text, out selectedThreads);
                threads = selectedThreads;
            }

            if (mainPictureBox.Image == null)
            {
                MessageBox.Show("Load an image first.");
                return;
            }

            Bitmap bitmap = new Bitmap(mainPictureBox.Image);
            int width = bitmap.Width;
            int height = bitmap.Height;

            // Uzyskaj dostęp do danych pikseli
            BitmapData bitmapData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height),
                                                    ImageLockMode.ReadWrite, PixelFormat.Format24bppRgb);

            IntPtr ptr = bitmapData.Scan0;

            int bytes = Math.Abs(bitmapData.Stride) * bitmap.Height;

            byte[] imageData = new byte[bytes];

            Marshal.Copy(ptr, imageData, 0, bytes);

            if (selectedLanguage == "C++")
            {
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                int chunkSize = height / selectedThreads;

                // Wywołaj funkcję C++ wielowątkowo
                Parallel.For(0, selectedThreads, threadIndex =>
                {
                    int startY = threadIndex * chunkSize;
                    int endY = (threadIndex == selectedThreads - 1) ? height : startY + chunkSize;

                    for (int y = startY; y < endY; y++)
                    {
                        ProcessImageCPP(imageData, width, height, power, xValues, yValues, pointCounter, new_red, new_green, new_blue, y);
                    }
                });
                stopwatch.Stop();
                TimeSpan elapsedTime = stopwatch.Elapsed;
                string v = elapsedTime.TotalMilliseconds.ToString("0.###");
                textBox1.Text = v;
            }
            else if (selectedLanguage == "ASM")
            {
                float[] tempPixelValues = new float[3];
                float[] pixelAdjuster = new float[3];
                pixelAdjuster[0] = new_red;
                pixelAdjuster[1] = new_green;
                pixelAdjuster[2] = new_blue;
                byte[] imageData2 = new byte[bytes];
                int[] index = new int[bytes];
                int c = 0;
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                for (int y = 0; y < height; ++y)
                {
                    for (int x = 0; x < width; ++x)
                    {
                        if (!IsPointInsidePolygon(x, y, xValues, yValues, pointCounter))
                        {
                            int startIndex = (y * width + x) * 3;
                            imageData2[startIndex] = imageData[startIndex];
                            imageData2[startIndex + 1] = imageData[startIndex + 1];
                            imageData2[startIndex + 2] = imageData[startIndex + 2];
                            index[c] = startIndex;
                            c++;
                        }
                    }
                }
                int chunkSize = imageData2.Length / selectedThreads;

                Parallel.For(0, selectedThreads, threadIndex =>
                {
                    int start = threadIndex * chunkSize;
                    int end = (threadIndex == selectedThreads - 1) ? imageData2.Length : start + chunkSize;

                    for (int i = start; i < end; i += 3)
                    {
                        tempPixelValues[0] = imageData2[i];
                        tempPixelValues[1] = imageData2[i + 1];
                        tempPixelValues[2] = imageData2[i + 2];

                        ProcessImageASM(tempPixelValues, pixelAdjuster);

                        imageData2[i] = (byte)tempPixelValues[0];
                        imageData2[i + 1] = (byte)tempPixelValues[1];
                        imageData2[i + 2] = (byte)tempPixelValues[2];
                        imageData[index[i]] = imageData2[i];
                        imageData[index[i] + 1] = imageData2[i + 1];
                        imageData[index[i] + 2] = imageData2[i + 2];
                    }

                });
                stopwatch.Stop();
                TimeSpan elapsedTime = stopwatch.Elapsed;
                string v = elapsedTime.TotalMilliseconds.ToString("0.###");
                textBox2.Text = v;

                Marshal.Copy(imageData, 0, ptr, bytes);

                bitmap.UnlockBits(bitmapData);

                mainPictureBox.Image = bitmap;

                mainPictureBox.Invalidate();

            }
        }

        public static bool IsPointInsidePolygon(int x, int y, int[] xValues, int[] yValues, int pointCount)
        {
            bool inside = false;
            int count = 0;

            for (int i = 0, j = pointCount - 1; i < pointCount; j = i++)
            {
                if ((yValues[i] > y) != (yValues[j] > y) &&
                    (x < (xValues[j] - xValues[i]) * (double)(y - yValues[i]) / (double)(yValues[j] - yValues[i]) + xValues[i]))
                {
                    count += 1;
                }
            }

            inside = (count % 2 == 1);
            return inside;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            //Threads

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            //ASM Timer

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //C++ timer

        }

        private void languageComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            selectedIndex = languageComboBox.SelectedIndex;
            if (selectedIndex == 0)
            {
                selectedLanguage = "C++";
            }
            else if (selectedIndex == 1)
            {
                selectedLanguage = "ASM";
            }
        }

        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {
            //toolStripTextBox1.Text = power.ToString();
        }

        private void Clipper_Click(object sender, EventArgs e)
        {
            isCutterSelected = !isCutterSelected;
            clipperActivationStatus.Text = isCutterSelected ? "Clipper activated" : "Clipper deactivated";
        }
    }
}
