using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CommsProtoGUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Open();
            char[] buffer = new char[1];
            buffer[0] = '2';
            serialPort1.Write(buffer, 0, 1);
            serialPort1.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Open();
            char[] buffer = new char[1];
            buffer[0] = '1';
            serialPort1.Write(buffer, 0, 1);
            serialPort1.Close();
        }
    }
}
