using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DawidPerdekLab4.Repository.Command;
using DawidPerdekLab4.Repository.Query;
using DawidPerdekLab4.Model;
using DawidPerdekLab4.Repository.Query.Interfaces;

namespace DawidPerdekLab4
{
    public partial class FormMain : Form
    {
        private readonly DawidPerdekContext _context;
        private readonly WriteRepository<Student> _writeStudentRepository;
        private readonly ReadRepository<Student> _readStudentRepository;
        private readonly IUserQuery _userQuery;

        public FormMain()
        {
            _context = new DawidPerdekContext();
            _writeStudentRepository = new WriteRepository<Student>(_context);
            _readStudentRepository = new ReadRepository<Student>(_context);
            _userQuery = new UserQuery(_context);
            InitializeComponent();
        }

        private void buttonAddNewStudent_Click(object sender, EventArgs e)
        {
            Student student = new Student()
            {
                Name = textBoxNewStudentName.Text.ToString(),
                Surname = textBoxNewStudentSurname.Text.ToString(),
                Index = textBoxNewStudentIndex.Text.ToString(),
                Address = new Address()
                {
                    City = textBoxNewStudentCity.Text.ToString(),
                    PostCode = textBoxNewStudentPostCode.Text.ToString()
                }
            };
            _writeStudentRepository.Create(student);
        }

        private void buttonShowStudents_Click(object sender, EventArgs e)
        {
            dataGridViewStudents.DataSource = null;
            dataGridViewStudents.DataSource = _userQuery.UserWithAddressByName(textBoxStudentName.Text.ToString())
                                            .Select(x => new
                                            {
                                                Imię = x.Name,
                                                Nazwisko = x.Surname,
                                                Miasto = x.Address.City,
                                                KodPocztowy = x.Address.PostCode
                                            })
                                            .ToList();
        }

        private void buttonShowAllStudents_Click(object sender, EventArgs e)
        {
            dataGridViewStudents.DataSource = null;
            dataGridViewStudents.DataSource = _readStudentRepository.GetAll()
                                            .Select(x => new
                                            {
                                                Imię = x.Name,
                                                Nazwisko = x.Surname,
                                                Miasto = x.Address.City,
                                                KodPocztowy = x.Address.PostCode
                                            })
                                            .ToList();
        }
    }
}
