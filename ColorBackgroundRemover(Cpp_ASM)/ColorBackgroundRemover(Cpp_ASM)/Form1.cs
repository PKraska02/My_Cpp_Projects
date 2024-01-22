using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
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
        private byte[] imageData; // Dane obrazu
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
        Color clickedColor;
        [DllImport(@"C:\Users\Piotr\source\repos\My_Cpp_Projects\ColorBackgroundRemover(Cpp_ASM)\x64\Release\ASMColorRemoverLIB.dll")]
        static extern void ProcessImageASM();
        [DllImport(@"C:\Users\Piotr\source\repos\My_Cpp_Projects\ColorBackgroundRemover(Cpp_ASM)\x64\Release\CPPColorRemoverLIB.dll")]
        static extern void ProcessImageCPP(byte[] imageData, int width, int height, int power, int[] xValues, int[] yValues, int pointcount,int new_red,int new_green, int new_blue);
        public GUI()
        {
            InitializeComponent();
            imageData = null; // Tutaj możesz zainicjować dane obrazu
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

            // Przygotuj wskaźnik do pierwszego piksela
            IntPtr ptr = bitmapData.Scan0;

            // Oblicz rozmiar danych pikseli w bajtach
            int bytes = Math.Abs(bitmapData.Stride) * bitmap.Height;

            // Przygotuj bufor danych
            byte[] imageData = new byte[bytes];

            // Skopiuj dane z obrazu do bufora
            Marshal.Copy(ptr, imageData, 0, bytes);

            // Sprawdź wybrany język w ComboBoxie
            if (selectedLanguage == "C++")
            {
                // Wywołaj funkcję C++
                ProcessImageCPP(imageData, width, height, power, xValues, yValues, pointCounter,new_red,new_green,new_blue);
            }
            else if (selectedLanguage == "ASM")
            {
                // Wywołaj funkcję ASM
                ProcessImageASM(int & red, int & green, int & blue, int power, int new_red, int new_green, int new_blue);
            }

            // Skopiuj zmodyfikowane dane z powrotem do obrazu
            Marshal.Copy(imageData, 0, ptr, bytes);

            // Zwolnij zasoby
            bitmap.UnlockBits(bitmapData);

            // Przypisz zmodyfikowany obraz z powrotem do PictureBox
            mainPictureBox.Image = bitmap;

            // Odśwież PictureBox
            mainPictureBox.Invalidate();

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
