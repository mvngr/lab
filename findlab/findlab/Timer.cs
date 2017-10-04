using System;
using System.Diagnostics;
using System.Threading;

namespace findlab
{
    public class Timer
    {
        private Stopwatch stopWatch;
        public Timer()
        {
            stopWatch = new Stopwatch();
        }

        public void startTimer()
        {
            stopWatch.Reset();
            stopWatch.Start();
        }

        public string stopTimer(){
            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;
            return String.Format("{0:00}:{1:00}:{2:00}.{3:000}",
                ts.Hours, ts.Minutes, ts.Seconds,
                ts.Milliseconds);
        }
    }
}