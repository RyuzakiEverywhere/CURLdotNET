using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CURLdotNET
{
    public class TORDownloaded
    {

        [DllImport(@"curl_dll_lib.dll")]
        public static extern bool CheckTor(string filename_phpfile);
        public bool TOR_Downloaded(string php_name)
        {
            if(CheckTor(php_name))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
