using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Dse
{
    public class ValueCache : IDisposable
    {
        private MemoryStream _ms;
        private BinaryWriter _bw;

        public ValueCache()
        {
            _ms = new MemoryStream();
            _bw = new BinaryWriter(_ms);
        }

        public ValueCache(int capacity)
        {
            _ms = new MemoryStream(capacity);
            _bw = new BinaryWriter(_ms);
        }

        public void Dispose()
        {
            _bw.Close();
            _ms.Dispose();
        }

        public void Clear()
        {
            _ms.SetLength(0);
        }

        public void Reserve(long num)
        {
            if (num < 0)
            {
                throw new ArgumentException("num");
            }

            Ensure(_ms.Length + num);
        }

        public void Ensure(long num)
        {
            if (num < 0)
            {
                throw new ArgumentException("num");
            }

            if (num > _ms.Capacity)
            {
                Int64 length = _ms.Length;
                _ms.SetLength(num);
                _ms.SetLength(length);
            }
        }

        public ValueCache Add(byte value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(sbyte value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(short value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(ushort value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(int value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(uint value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(long value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(ulong value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(float value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(double value)
        {
            _bw.Write(value);

            return this;
        }

        public ValueCache Add(byte[] buffer)
        {
            _bw.Write(buffer);

            return this;
        }

        public ValueCache Add(byte[] buffer, int index, int count)
        {
            _bw.Write(buffer, index, count);

            return this;
        }

        public ValueCache Add(short[] buffer)
        {
            foreach (short s in buffer)
            {
                _bw.Write(s);
            }

            return this;
        }

        public ValueCache Add(S_VibCharValue value)
        {
            _bw.Write(value._fCharAll);
            _bw.Write(value._fCharHalf);
            _bw.Write(value._fCharOne);
            _bw.Write(value._fCharTwo);
            _bw.Write(value._fCharThree);
            _bw.Write(value._fCharRes);
            _bw.Write(value._fDC);
            _bw.Write(value._fGap);
            _bw.Write(value._fPhaseHalf);
            _bw.Write(value._fPhaseOne);
            _bw.Write(value._fPhaseTwo);
            _bw.Write(value._fPhaseThree);
            _bw.Write(value._iSmpFreq);
            _bw.Write(value._iSmpNum);
            _bw.Write(value._iRev);

            return this;
        }

        public ValueCache Add(S_VibCharValue[] valarr)
        {
            foreach (S_VibCharValue value in valarr)
            {
                Add(value);
            }

            return this;
        }

        public byte[] ToArray()
        {
            return _ms.ToArray();
        }
    }
}
