﻿using System;
using System.Threading;

namespace _1._1
{
    /// <summary>
    /// Multiple threaded lazy
    /// </summary>
    public class LazyMultipleThreaded<T> : ILazy<T>
    {
        private T value;
        private bool isValueCreated;
        private Func<T> func;
        private static Object lockObject = new Object();

        public LazyMultipleThreaded(Func<T> func)
        {
            this.func = func;
        }

        /// <summary>
        /// Returns value
        /// </summary>
        /// <returns>Value</returns>
        public T Get()
        {
            if (func == null)
            {
                throw new FuncNullException();
            }

            
            if (!isValueCreated)
            {
                lock (lockObject)
                {
                    if (!Volatile.Read(ref isValueCreated))
                    {
                        value = func();
                        isValueCreated = true;
                        func = null;
                    }
                }
            }
            return value;
        }
    }
}
