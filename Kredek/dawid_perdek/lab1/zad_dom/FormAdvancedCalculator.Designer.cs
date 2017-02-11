namespace DawidPerdekZad1
{
    partial class FormAdvancedCalculator
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.textBoxEquationAdvanced = new System.Windows.Forms.TextBox();
            this.labelPrompt = new System.Windows.Forms.Label();
            this.buttonCalculateXParse = new System.Windows.Forms.Button();
            this.buttonCalculateY = new System.Windows.Forms.Button();
            this.textBoxLeft = new System.Windows.Forms.TextBox();
            this.textBoxRight = new System.Windows.Forms.TextBox();
            this.labelArguments = new System.Windows.Forms.Label();
            this.chartY = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.labelResult = new System.Windows.Forms.Label();
            this.textBoxResult = new System.Windows.Forms.TextBox();
            this.buttonCalculateXStack = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.chartY)).BeginInit();
            this.SuspendLayout();
            // 
            // textBoxEquationAdvanced
            // 
            this.textBoxEquationAdvanced.BackColor = System.Drawing.SystemColors.MenuBar;
            this.textBoxEquationAdvanced.CharacterCasing = System.Windows.Forms.CharacterCasing.Lower;
            this.textBoxEquationAdvanced.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.textBoxEquationAdvanced.ForeColor = System.Drawing.SystemColors.GrayText;
            this.textBoxEquationAdvanced.Location = new System.Drawing.Point(13, 45);
            this.textBoxEquationAdvanced.Name = "textBoxEquationAdvanced";
            this.textBoxEquationAdvanced.Size = new System.Drawing.Size(380, 26);
            this.textBoxEquationAdvanced.TabIndex = 0;
            this.textBoxEquationAdvanced.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // labelPrompt
            // 
            this.labelPrompt.AutoSize = true;
            this.labelPrompt.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelPrompt.Location = new System.Drawing.Point(31, 9);
            this.labelPrompt.Name = "labelPrompt";
            this.labelPrompt.Size = new System.Drawing.Size(351, 20);
            this.labelPrompt.TabIndex = 1;
            this.labelPrompt.Text = "wprowadź równanie w postaci:   x = ...   lub   y = ...";
            // 
            // buttonCalculateXParse
            // 
            this.buttonCalculateXParse.Location = new System.Drawing.Point(12, 77);
            this.buttonCalculateXParse.Name = "buttonCalculateXParse";
            this.buttonCalculateXParse.Size = new System.Drawing.Size(153, 23);
            this.buttonCalculateXParse.TabIndex = 2;
            this.buttonCalculateXParse.Text = "Wylicz X - parsowanie";
            this.buttonCalculateXParse.UseVisualStyleBackColor = true;
            this.buttonCalculateXParse.Click += new System.EventHandler(this.buttonCalculateXParse_Click);
            // 
            // buttonCalculateY
            // 
            this.buttonCalculateY.Location = new System.Drawing.Point(231, 90);
            this.buttonCalculateY.Name = "buttonCalculateY";
            this.buttonCalculateY.Size = new System.Drawing.Size(75, 23);
            this.buttonCalculateY.TabIndex = 3;
            this.buttonCalculateY.Text = "Przelicz Y";
            this.buttonCalculateY.UseVisualStyleBackColor = true;
            this.buttonCalculateY.Click += new System.EventHandler(this.buttonCalculateY_Click);
            // 
            // textBoxLeft
            // 
            this.textBoxLeft.Location = new System.Drawing.Point(231, 145);
            this.textBoxLeft.Name = "textBoxLeft";
            this.textBoxLeft.Size = new System.Drawing.Size(61, 20);
            this.textBoxLeft.TabIndex = 4;
            this.textBoxLeft.Text = "0";
            // 
            // textBoxRight
            // 
            this.textBoxRight.Location = new System.Drawing.Point(321, 145);
            this.textBoxRight.Name = "textBoxRight";
            this.textBoxRight.Size = new System.Drawing.Size(61, 20);
            this.textBoxRight.TabIndex = 5;
            this.textBoxRight.Text = "0";
            // 
            // labelArguments
            // 
            this.labelArguments.AutoSize = true;
            this.labelArguments.Location = new System.Drawing.Point(254, 129);
            this.labelArguments.Name = "labelArguments";
            this.labelArguments.Size = new System.Drawing.Size(105, 13);
            this.labelArguments.TabIndex = 6;
            this.labelArguments.Text = "Przedział wartości \'x\'";
            // 
            // chartY
            // 
            chartArea1.Name = "ChartArea1";
            this.chartY.ChartAreas.Add(chartArea1);
            this.chartY.Location = new System.Drawing.Point(13, 203);
            this.chartY.Name = "chartY";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.FastLine;
            series1.Name = "Data";
            this.chartY.Series.Add(series1);
            this.chartY.Size = new System.Drawing.Size(370, 270);
            this.chartY.TabIndex = 7;
            this.chartY.Text = "y = ...";
            // 
            // labelResult
            // 
            this.labelResult.AutoSize = true;
            this.labelResult.Location = new System.Drawing.Point(12, 158);
            this.labelResult.Name = "labelResult";
            this.labelResult.Size = new System.Drawing.Size(72, 13);
            this.labelResult.TabIndex = 8;
            this.labelResult.Text = "Wynik:   x =   ";
            // 
            // textBoxResult
            // 
            this.textBoxResult.Location = new System.Drawing.Point(90, 155);
            this.textBoxResult.Name = "textBoxResult";
            this.textBoxResult.ReadOnly = true;
            this.textBoxResult.Size = new System.Drawing.Size(75, 20);
            this.textBoxResult.TabIndex = 9;
            // 
            // buttonCalculateXStack
            // 
            this.buttonCalculateXStack.Location = new System.Drawing.Point(13, 103);
            this.buttonCalculateXStack.Name = "buttonCalculateXStack";
            this.buttonCalculateXStack.Size = new System.Drawing.Size(152, 23);
            this.buttonCalculateXStack.TabIndex = 10;
            this.buttonCalculateXStack.Text = "Wylicz X - stos";
            this.buttonCalculateXStack.UseVisualStyleBackColor = true;
            this.buttonCalculateXStack.Click += new System.EventHandler(this.buttonCalculateXStack_Click);
            // 
            // FormAdvancedCalculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(404, 512);
            this.Controls.Add(this.buttonCalculateXStack);
            this.Controls.Add(this.textBoxResult);
            this.Controls.Add(this.labelResult);
            this.Controls.Add(this.chartY);
            this.Controls.Add(this.labelArguments);
            this.Controls.Add(this.textBoxRight);
            this.Controls.Add(this.textBoxLeft);
            this.Controls.Add(this.buttonCalculateY);
            this.Controls.Add(this.buttonCalculateXParse);
            this.Controls.Add(this.labelPrompt);
            this.Controls.Add(this.textBoxEquationAdvanced);
            this.Name = "FormAdvancedCalculator";
            this.Text = "Kalkulator zaawansowany";
            ((System.ComponentModel.ISupportInitialize)(this.chartY)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxEquationAdvanced;
        private System.Windows.Forms.Label labelPrompt;
        private System.Windows.Forms.Button buttonCalculateXParse;
        private System.Windows.Forms.Button buttonCalculateY;
        private System.Windows.Forms.TextBox textBoxLeft;
        private System.Windows.Forms.TextBox textBoxRight;
        private System.Windows.Forms.Label labelArguments;
        private System.Windows.Forms.DataVisualization.Charting.Chart chartY;
        private System.Windows.Forms.Label labelResult;
        private System.Windows.Forms.TextBox textBoxResult;
        private System.Windows.Forms.Button buttonCalculateXStack;
    }
}