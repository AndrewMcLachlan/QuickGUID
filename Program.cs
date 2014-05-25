using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Asm.QuickGuid
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            Clipboard.SetText(Guid.NewGuid().ToString("D").ToLowerInvariant());
        }
    }
}
