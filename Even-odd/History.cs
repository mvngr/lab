using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S_triangle
{
    class History
    {
        List<string> log;
        private const string LINE = "************";

        public History()
        {
            log = new List<string>();
        }
        public string Log
        {
            get
            {
                if (log.Count == 0)
                    return "";
                string res = "";
                foreach (string i in log)
                    res = res + i + '\n';
                res += LINE;
                return res;
            }
            set
            {
                log.Add(value);
                if (log.Count > 10)
                    log.RemoveAt(0);
            }
        }
    }
}
