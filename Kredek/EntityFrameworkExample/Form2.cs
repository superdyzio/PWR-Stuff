using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Example.Repository.Query.Interfaces;
using Ninject;

namespace Example
{
    public partial class Form2 : Form
    {
        private readonly IStuffQuery _stuffQuery;
        [Inject]
        public Form2(IStuffQuery stuffQuery)
        {
            _stuffQuery = stuffQuery;
            InitializeComponent();
        }
    }
}
