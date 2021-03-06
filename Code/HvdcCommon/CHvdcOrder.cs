///////////////////////////////////////////////////////////
//  CmcOrder.cs
//  Implementation of the Class CmcOrder
//  Generated by Enterprise Architect
//  Created on:      27-5月-2017 9:49:58
//  Original author: open2
///////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Hvdc.MT.HvdcCommon
{
    public class CHvdcOrder
    {
        public CHvdcOrder()
        {
            Init();
        }

        public virtual void Init()
        {
            //
            nValNum = 1;

            Flag_Ground = "1111";   //接地：单极大地/金属回线/双极/双极并联
            Flag_Ud = "111";        //直流电压：全压/80%/70%
            Flag_Rd = "110";        //直流电阻：高阻/低阻/额定
            Flag_Uac = "1111";      //交流电压：最大/额定/最小/极小

            //Is6Pulse = 0;       //是否六脉动中间接地 
            IsUdCustom = 0;     //直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
            IsUacSwap = 0;       // 是否交流电压交叉
            IsUdToGround = 0;   //直流电压对地或对中性线
            
            //string Flag_IsPdSingle = "0";//是否单功率水平，该成员可以不要，当成员BdSize取值为1时即为但功率水平
            PdStartPer = 10;    //起始功率水平
            PdIncrePer = 5;     //功率水平增量
            PdSize = 29;        //功率水平数

        }

        public string CalName;
        /// <summary>
        /// 单极大地/金属回线/双极/双极并联
        /// </summary>
        public string Flag_Ground = "1111";
        /// <summary>
        /// 全压/80%/70%
        /// </summary>
        public string Flag_Ud = "111";
        /// <summary>
        /// 高阻/低阻（额定）
        /// </summary>
        public string Flag_Rd = "110";
        /// <summary>
        /// 额定/最大/最小/极小
        /// </summary>
        public string Flag_Uac = "1111";
        /// <summary>
        /// 阀组数
        /// </summary>
        public int nValNum = 1;
        /// <summary>
        /// 直流电压预设情况，如预设则使用UdCustom作为电压指令，否则使用UdLevel
        /// </summary>
        public int IsUdCustom = 0;
        /// <summary>
        /// 是否交流电压交叉
        /// </summary>
        public int IsUacSwap = 0;
        public int IsUdToGround = 0;

        //public int Is6Pulse = 0;

        /// <summary>
        /// 起始功率水平
        /// </summary>
        public double PdStartPer = 10;
        /// <summary>
        /// 功率水平增量
        /// </summary>
        public double PdIncrePer = 5;
        /// <summary>
        /// 功率水平数
        /// </summary>
        public int PdSize = 29;

        /// <summary>
        /// 是否单负荷，0=单;1=多，默认多
        /// </summary>
        public int IsLoadSingle = 1;

        /// <summary>
        /// 单负荷直流电压
        /// </summary>
        public double UdSingle;

        /// <summary>
        /// 单负荷直流功率
        /// </summary>
        public double PdSingle;


    }//end CmcOrder

}//end namespace HvdcCommon