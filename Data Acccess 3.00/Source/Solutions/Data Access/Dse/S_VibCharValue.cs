using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Dse
{
   public class S_VibCharValue
    {
        public float _fCharAll;    //通频特征值
        public float _fCharHalf;   //1/2分频特征值
        public float _fCharOne;    //1倍频特征值
        public float _fCharTwo;    //2倍频特征值
        public float _fCharThree;  //3倍频特征值
        public float _fCharRes;    //残振特征值
        public float _fDC;         //直流量
        public float _fGap;        //间隙值
        public float _fPhaseHalf;  //1/2分频相位
        public float _fPhaseOne;   //1倍频相位
        public float _fPhaseTwo;   //2倍频相位
        public float _fPhaseThree; //3倍频相位

        public int _iSmpFreq;    //采样频率
        public int _iSmpNum;     //采样点数
        public int _iRev;        //转速

        public static int Size
        {
            get
            {
                return (12 * sizeof(float) + 3 * sizeof(int));
            }
        }

        public void Clear()
        {
            _fCharAll = 0;
            _fCharHalf = 0;
            _fCharOne = 0;
            _fCharTwo = 0;
            _fCharThree = 0;
            _fCharRes = 0;
            _fDC = 0;
            _fGap = 0;
            _fPhaseHalf = 0;
            _fPhaseOne = 0;
            _fPhaseTwo = 0;
            _fPhaseThree = 0;

            _iSmpFreq = 0;
            _iSmpNum = 0;
            _iRev = 0;
        }

        public byte[] GetBytes()
        {
            int length = 12 * sizeof(float) + 3 * sizeof(int);

            var bytes = new byte[length];

            using (var ms = new MemoryStream(bytes))
            {
                using (var bw = new BinaryWriter(ms))
                {
                    bw.Write(_fCharAll);
                    bw.Write(_fCharHalf);
                    bw.Write(_fCharOne);
                    bw.Write(_fCharTwo);
                    bw.Write(_fCharThree);
                    bw.Write(_fCharRes);
                    bw.Write(_fDC);
                    bw.Write(_fGap);
                    bw.Write(_fPhaseHalf);
                    bw.Write(_fPhaseOne);
                    bw.Write(_fPhaseTwo);
                    bw.Write(_fPhaseThree);

                    bw.Write(_iSmpFreq);
                    bw.Write(_iSmpNum);
                    bw.Write(_iRev);
                }
            }

            return bytes;
        }
    }
}
