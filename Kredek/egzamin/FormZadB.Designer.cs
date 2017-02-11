namespace DawidPerdek
{
    partial class FormZadB
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.textBoxInput = new System.Windows.Forms.TextBox();
            this.labelInput = new System.Windows.Forms.Label();
            this.buttonCount = new System.Windows.Forms.Button();
            this.buttonSmallerForm = new System.Windows.Forms.Button();
            this.buttonBiggerForm = new System.Windows.Forms.Button();
            this.buttonProgressBar = new System.Windows.Forms.Button();
            this.progressBarTimer = new System.Windows.Forms.ProgressBar();
            this.timerProgressBar = new System.Windows.Forms.Timer(this.components);
            this.buttonFormZadA = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxInput
            // 
            this.textBoxInput.Location = new System.Drawing.Point(24, 36);
            this.textBoxInput.Name = "textBoxInput";
            this.textBoxInput.Size = new System.Drawing.Size(209, 20);
            this.textBoxInput.TabIndex = 0;
            // 
            // labelInput
            // 
            this.labelInput.AutoSize = true;
            this.labelInput.Location = new System.Drawing.Point(21, 9);
            this.labelInput.Name = "labelInput";
            this.labelInput.Size = new System.Drawing.Size(63, 13);
            this.labelInput.TabIndex = 1;
            this.labelInput.Text = "Podaj tekst:";
            // 
            // buttonCount
            // 
            this.buttonCount.Location = new System.Drawing.Point(133, 4);
            this.buttonCount.Name = "buttonCount";
            this.buttonCount.Size = new System.Drawing.Size(100, 23);
            this.buttonCount.TabIndex = 2;
            this.buttonCount.Text = "B.1 Policz";
            this.buttonCount.UseVisualStyleBackColor = true;
            this.buttonCount.UseWaitCursor = true;
            this.buttonCount.Click += new System.EventHandler(this.buttonCount_Click);
            // 
            // buttonSmallerForm
            // 
            this.buttonSmallerForm.Location = new System.Drawing.Point(24, 62);
            this.buttonSmallerForm.Name = "buttonSmallerForm";
            this.buttonSmallerForm.Size = new System.Drawing.Size(50, 50);
            this.buttonSmallerForm.TabIndex = 3;
            this.buttonSmallerForm.Text = "<-";
            this.buttonSmallerForm.UseVisualStyleBackColor = true;
            this.buttonSmallerForm.UseWaitCursor = true;
            this.buttonSmallerForm.Click += new System.EventHandler(this.buttonSmallerForm_Click);
            // 
            // buttonBiggerForm
            // 
            this.buttonBiggerForm.Location = new System.Drawing.Point(183, 62);
            this.buttonBiggerForm.Name = "buttonBiggerForm";
            this.buttonBiggerForm.Size = new System.Drawing.Size(50, 50);
            this.buttonBiggerForm.TabIndex = 4;
            this.buttonBiggerForm.Text = "->";
            this.buttonBiggerForm.UseVisualStyleBackColor = true;
            this.buttonBiggerForm.UseWaitCursor = true;
            this.buttonBiggerForm.Click += new System.EventHandler(this.buttonBiggerForm_Click);
            // 
            // buttonProgressBar
            // 
            this.buttonProgressBar.Location = new System.Drawing.Point(88, 62);
            this.buttonProgressBar.Name = "buttonProgressBar";
            this.buttonProgressBar.Size = new System.Drawing.Size(82, 50);
            this.buttonProgressBar.TabIndex = 5;
            this.buttonProgressBar.Text = "B.3 Pasek postępu";
            this.buttonProgressBar.UseVisualStyleBackColor = true;
            this.buttonProgressBar.UseWaitCursor = true;
            this.buttonProgressBar.Click += new System.EventHandler(this.buttonProgressBar_Click);
            // 
            // progressBarTimer
            // 
            this.progressBarTimer.Location = new System.Drawing.Point(24, 118);
            this.progressBarTimer.Maximum = 200;
            this.progressBarTimer.Name = "progressBarTimer";
            this.progressBarTimer.Size = new System.Drawing.Size(209, 23);
            this.progressBarTimer.TabIndex = 6;
            this.progressBarTimer.Value = 200;
            this.progressBarTimer.Visible = false;
            // 
            // timerProgressBar
            // 
            this.timerProgressBar.Tick += new System.EventHandler(this.timerProgressBar_Tick);
            // 
            // buttonFormZadA
            // 
            this.buttonFormZadA.Location = new System.Drawing.Point(239, 62);
            this.buttonFormZadA.Name = "buttonFormZadA";
            this.buttonFormZadA.Size = new System.Drawing.Size(46, 23);
            this.buttonFormZadA.TabIndex = 7;
            this.buttonFormZadA.Text = "Zad A";
            this.buttonFormZadA.UseVisualStyleBackColor = true;
            this.buttonFormZadA.UseWaitCursor = true;
            this.buttonFormZadA.Click += new System.EventHandler(this.buttonFormZadA_Click);
            // 
            // FormZadB
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(444, 172);
            this.Controls.Add(this.buttonFormZadA);
            this.Controls.Add(this.progressBarTimer);
            this.Controls.Add(this.buttonProgressBar);
            this.Controls.Add(this.buttonBiggerForm);
            this.Controls.Add(this.buttonSmallerForm);
            this.Controls.Add(this.buttonCount);
            this.Controls.Add(this.labelInput);
            this.Controls.Add(this.textBoxInput);
            this.MaximumSize = new System.Drawing.Size(800, 700);
            this.MinimumSize = new System.Drawing.Size(255, 190);
            this.Name = "FormZadB";
            this.Text = "Zadanie B";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxInput;
        private System.Windows.Forms.Label labelInput;
        private System.Windows.Forms.Button buttonCount;
        private System.Windows.Forms.Button buttonSmallerForm;
        private System.Windows.Forms.Button buttonBiggerForm;
        private System.Windows.Forms.Button buttonProgressBar;
        private System.Windows.Forms.ProgressBar progressBarTimer;
        private System.Windows.Forms.Timer timerProgressBar;
        private System.Windows.Forms.Button buttonFormZadA;
    }
}

