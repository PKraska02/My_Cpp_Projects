namespace ColorBackgroundRemover_Cpp_ASM_
{
    partial class GUI
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(GUI));
            this.loadImage = new System.Windows.Forms.Button();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.pipetteButton = new System.Windows.Forms.ToolStripButton();
            this.pippeteLabel = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.decreasePowerButton = new System.Windows.Forms.ToolStripButton();
            this.decreasePowerLabel = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.increasePowerButton = new System.Windows.Forms.ToolStripButton();
            this.increasePowerLabel = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.pippeteActivationStatus = new System.Windows.Forms.ToolStripLabel();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.clipperActivationStatus = new System.Windows.Forms.ToolStripLabel();
            this.Clipper = new System.Windows.Forms.ToolStripButton();
            this.ClipperLabel = new System.Windows.Forms.ToolStripLabel();
            this.mainPanel = new System.Windows.Forms.Panel();
            this.mainPictureBox = new System.Windows.Forms.PictureBox();
            this.languageComboBox = new System.Windows.Forms.ComboBox();
            this.comboboxLabel = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.timersLabel = new System.Windows.Forms.Label();
            this.cppLabel = new System.Windows.Forms.Label();
            this.asmLabel = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.threadLabel = new System.Windows.Forms.Label();
            this.runButton = new System.Windows.Forms.Button();
            this.toolStrip1.SuspendLayout();
            this.mainPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // loadImage
            // 
            this.loadImage.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.loadImage.Location = new System.Drawing.Point(31, 677);
            this.loadImage.Name = "loadImage";
            this.loadImage.Size = new System.Drawing.Size(128, 56);
            this.loadImage.TabIndex = 0;
            this.loadImage.Text = "Load Image";
            this.loadImage.UseVisualStyleBackColor = true;
            this.loadImage.Click += new System.EventHandler(this.loadImage_Click);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.pipetteButton,
            this.pippeteLabel,
            this.toolStripSeparator1,
            this.toolStripTextBox1,
            this.toolStripSeparator2,
            this.decreasePowerButton,
            this.decreasePowerLabel,
            this.toolStripSeparator3,
            this.increasePowerButton,
            this.increasePowerLabel,
            this.toolStripSeparator4,
            this.pippeteActivationStatus,
            this.toolStripSeparator5,
            this.clipperActivationStatus,
            this.Clipper,
            this.ClipperLabel});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1261, 25);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // pipetteButton
            // 
            this.pipetteButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.pipetteButton.Image = ((System.Drawing.Image)(resources.GetObject("pipetteButton.Image")));
            this.pipetteButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.pipetteButton.Name = "pipetteButton";
            this.pipetteButton.Size = new System.Drawing.Size(23, 22);
            this.pipetteButton.Text = "toolStripButton1";
            this.pipetteButton.Click += new System.EventHandler(this.toolStripButton1_Click);
            // 
            // pippeteLabel
            // 
            this.pippeteLabel.Name = "pippeteLabel";
            this.pippeteLabel.Size = new System.Drawing.Size(47, 22);
            this.pippeteLabel.Text = "Pippete";
            this.pippeteLabel.Click += new System.EventHandler(this.pippeteLabel_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.Font = new System.Drawing.Font("Segoe UI", 9F);
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size(100, 25);
            this.toolStripTextBox1.Click += new System.EventHandler(this.toolStripTextBox1_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // decreasePowerButton
            // 
            this.decreasePowerButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.decreasePowerButton.Image = ((System.Drawing.Image)(resources.GetObject("decreasePowerButton.Image")));
            this.decreasePowerButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.decreasePowerButton.Name = "decreasePowerButton";
            this.decreasePowerButton.Size = new System.Drawing.Size(23, 22);
            this.decreasePowerButton.Text = "toolStripButton2";
            this.decreasePowerButton.Click += new System.EventHandler(this.toolStripButton2_Click);
            // 
            // decreasePowerLabel
            // 
            this.decreasePowerLabel.Name = "decreasePowerLabel";
            this.decreasePowerLabel.Size = new System.Drawing.Size(90, 22);
            this.decreasePowerLabel.Text = "Decrease power";
            this.decreasePowerLabel.Click += new System.EventHandler(this.decreasePowerButton_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // increasePowerButton
            // 
            this.increasePowerButton.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.increasePowerButton.Image = ((System.Drawing.Image)(resources.GetObject("increasePowerButton.Image")));
            this.increasePowerButton.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.increasePowerButton.Name = "increasePowerButton";
            this.increasePowerButton.Size = new System.Drawing.Size(23, 22);
            this.increasePowerButton.Text = "toolStripButton3";
            this.increasePowerButton.Click += new System.EventHandler(this.toolStripButton3_Click);
            // 
            // increasePowerLabel
            // 
            this.increasePowerLabel.Name = "increasePowerLabel";
            this.increasePowerLabel.Size = new System.Drawing.Size(86, 22);
            this.increasePowerLabel.Text = "Increase power";
            this.increasePowerLabel.Click += new System.EventHandler(this.increasePowerButton_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(6, 25);
            // 
            // pippeteActivationStatus
            // 
            this.pippeteActivationStatus.Name = "pippeteActivationStatus";
            this.pippeteActivationStatus.Size = new System.Drawing.Size(17, 22);
            this.pippeteActivationStatus.Text = "\"\"";
            this.pippeteActivationStatus.Click += new System.EventHandler(this.pippeteActivationStatus_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(6, 25);
            // 
            // clipperActivationStatus
            // 
            this.clipperActivationStatus.Name = "clipperActivationStatus";
            this.clipperActivationStatus.Size = new System.Drawing.Size(17, 22);
            this.clipperActivationStatus.Text = "\"\"";
            this.clipperActivationStatus.Click += new System.EventHandler(this.clipperActivationStatus_Click);
            // 
            // Clipper
            // 
            this.Clipper.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.Clipper.Image = ((System.Drawing.Image)(resources.GetObject("Clipper.Image")));
            this.Clipper.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.Clipper.Name = "Clipper";
            this.Clipper.Size = new System.Drawing.Size(23, 22);
            this.Clipper.Text = "Clipper";
            this.Clipper.Click += new System.EventHandler(this.Clipper_Click);
            // 
            // ClipperLabel
            // 
            this.ClipperLabel.Name = "ClipperLabel";
            this.ClipperLabel.Size = new System.Drawing.Size(52, 22);
            this.ClipperLabel.Text = "Clippper";
            // 
            // mainPanel
            // 
            this.mainPanel.Controls.Add(this.mainPictureBox);
            this.mainPanel.Location = new System.Drawing.Point(32, 75);
            this.mainPanel.Name = "mainPanel";
            this.mainPanel.Size = new System.Drawing.Size(829, 538);
            this.mainPanel.TabIndex = 2;
            this.mainPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.mainPanel_Paint);
            // 
            // mainPictureBox
            // 
            this.mainPictureBox.Location = new System.Drawing.Point(-3, 0);
            this.mainPictureBox.Name = "mainPictureBox";
            this.mainPictureBox.Size = new System.Drawing.Size(840, 545);
            this.mainPictureBox.TabIndex = 0;
            this.mainPictureBox.TabStop = false;
            this.mainPictureBox.Click += new System.EventHandler(this.mainPictureBox_Click);
            // 
            // languageComboBox
            // 
            this.languageComboBox.FormattingEnabled = true;
            this.languageComboBox.Location = new System.Drawing.Point(1081, 75);
            this.languageComboBox.Name = "languageComboBox";
            this.languageComboBox.Size = new System.Drawing.Size(121, 21);
            this.languageComboBox.TabIndex = 3;
            this.languageComboBox.SelectedIndexChanged += new System.EventHandler(this.languageComboBox_SelectedIndexChanged);
            // 
            // comboboxLabel
            // 
            this.comboboxLabel.AutoSize = true;
            this.comboboxLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.comboboxLabel.Location = new System.Drawing.Point(1093, 52);
            this.comboboxLabel.Name = "comboboxLabel";
            this.comboboxLabel.Size = new System.Drawing.Size(89, 20);
            this.comboboxLabel.TabIndex = 4;
            this.comboboxLabel.Text = "Language";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(1081, 207);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(121, 20);
            this.textBox1.TabIndex = 5;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(1081, 259);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(121, 20);
            this.textBox2.TabIndex = 6;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // timersLabel
            // 
            this.timersLabel.AutoSize = true;
            this.timersLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.timersLabel.Location = new System.Drawing.Point(1107, 172);
            this.timersLabel.Name = "timersLabel";
            this.timersLabel.Size = new System.Drawing.Size(62, 20);
            this.timersLabel.TabIndex = 7;
            this.timersLabel.Text = "Timers";
            // 
            // cppLabel
            // 
            this.cppLabel.AutoSize = true;
            this.cppLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.cppLabel.Location = new System.Drawing.Point(1023, 205);
            this.cppLabel.Name = "cppLabel";
            this.cppLabel.Size = new System.Drawing.Size(41, 20);
            this.cppLabel.TabIndex = 8;
            this.cppLabel.Text = "C++";
            // 
            // asmLabel
            // 
            this.asmLabel.AutoSize = true;
            this.asmLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.asmLabel.Location = new System.Drawing.Point(1023, 259);
            this.asmLabel.Name = "asmLabel";
            this.asmLabel.Size = new System.Drawing.Size(47, 20);
            this.asmLabel.TabIndex = 9;
            this.asmLabel.Text = "ASM";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(1081, 430);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(121, 20);
            this.textBox3.TabIndex = 10;
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // threadLabel
            // 
            this.threadLabel.AutoSize = true;
            this.threadLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.threadLabel.Location = new System.Drawing.Point(1107, 395);
            this.threadLabel.Name = "threadLabel";
            this.threadLabel.Size = new System.Drawing.Size(74, 20);
            this.threadLabel.TabIndex = 11;
            this.threadLabel.Text = "Threads";
            // 
            // runButton
            // 
            this.runButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.runButton.Location = new System.Drawing.Point(1018, 637);
            this.runButton.Name = "runButton";
            this.runButton.Size = new System.Drawing.Size(183, 85);
            this.runButton.TabIndex = 12;
            this.runButton.Text = "Run";
            this.runButton.UseVisualStyleBackColor = true;
            this.runButton.Click += new System.EventHandler(this.runButton_Click);
            // 
            // GUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1261, 774);
            this.Controls.Add(this.runButton);
            this.Controls.Add(this.threadLabel);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.asmLabel);
            this.Controls.Add(this.cppLabel);
            this.Controls.Add(this.timersLabel);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.comboboxLabel);
            this.Controls.Add(this.languageComboBox);
            this.Controls.Add(this.mainPanel);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.loadImage);
            this.Name = "GUI";
            this.Text = "ColorBackgroundRemover";
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.mainPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button loadImage;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton pipetteButton;
        private System.Windows.Forms.ToolStripLabel pippeteLabel;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox1;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton decreasePowerButton;
        private System.Windows.Forms.ToolStripLabel decreasePowerLabel;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripButton increasePowerButton;
        private System.Windows.Forms.ToolStripLabel increasePowerLabel;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripLabel pippeteActivationStatus;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripLabel clipperActivationStatus;
        private System.Windows.Forms.Panel mainPanel;
        private System.Windows.Forms.PictureBox mainPictureBox;
        private System.Windows.Forms.ComboBox languageComboBox;
        private System.Windows.Forms.Label comboboxLabel;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label timersLabel;
        private System.Windows.Forms.Label cppLabel;
        private System.Windows.Forms.Label asmLabel;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label threadLabel;
        private System.Windows.Forms.Button runButton;
        private System.Windows.Forms.ToolStripButton Clipper;
        private System.Windows.Forms.ToolStripLabel ClipperLabel;
    }
}

