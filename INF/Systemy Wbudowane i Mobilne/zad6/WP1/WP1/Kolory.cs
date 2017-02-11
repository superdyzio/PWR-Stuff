using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WP1
{
    class Kolory
    {
        public double calculateV(double r, double g, double b)
        {
            return (r + g + b) / (3 * 255);
        }

        public double calculateS(double r, double g, double b)
        {
            double max, min;
            if (r > g)
            {
                if (r > b)
                {
                    max = r;
                }
                else
                {
                    max = b;
                }

            }
            else
            {
                if (g > b)
                {
                    max = g;
                }
                else
                {
                    max = b;
                }
            }

            if (r < g)
            {
                if (r < b)
                {
                    min = r;
                }
                else
                {
                    min = b;
                }

            }
            else
            {
                if (g < b)
                {
                    min = g;
                }
                else
                {
                    min = b;
                }
            }

            return (max - min) / max;
        }
    }
}
