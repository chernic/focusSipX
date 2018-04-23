namespace FocusSipCsharpDemo
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.axFocusSip1 = new AxFocusSipAtlLib.AxFocusSip();
            ((System.ComponentModel.ISupportInitialize)(this.axFocusSip1)).BeginInit();
            this.SuspendLayout();
            // 
            // axFocusSip1
            // 
            this.axFocusSip1.Enabled = true;
            this.axFocusSip1.Location = new System.Drawing.Point(32, 12);
            this.axFocusSip1.Name = "axFocusSip1";
            this.axFocusSip1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axFocusSip1.OcxState")));
            this.axFocusSip1.Size = new System.Drawing.Size(192, 192);
            this.axFocusSip1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.axFocusSip1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.axFocusSip1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private AxFocusSipAtlLib.AxFocusSip axFocusSip1;


    }
}

