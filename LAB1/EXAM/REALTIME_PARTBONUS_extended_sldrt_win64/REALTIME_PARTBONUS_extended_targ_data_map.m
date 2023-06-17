  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (REALTIME_PARTBONUS_extended_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_P.sens
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_P.Aest
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PARTBONUS_extended_P.Ar
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 25;
	
	  ;% REALTIME_PARTBONUS_extended_P.Best
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 26;
	
	  ;% REALTIME_PARTBONUS_extended_P.Cest
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 36;
	
	  ;% REALTIME_PARTBONUS_extended_P.Tr
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 61;
	
	  ;% REALTIME_PARTBONUS_extended_P.deg2rad
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 62;
	
	  ;% REALTIME_PARTBONUS_extended_P.rad2deg
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 63;
	
	  ;% REALTIME_PARTBONUS_extended_P.rads2rpm
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 64;
	
	  ;% REALTIME_PARTBONUS_extended_P.rpm2rads
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 65;
	
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_FinalValue
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 66;
	
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_InitialValue
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 67;
	
	  ;% REALTIME_PARTBONUS_extended_P.EncoderInput1_InputFilter
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 68;
	
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_MaxMissedTicks
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 69;
	
	  ;% REALTIME_PARTBONUS_extended_P.EncoderInput1_MaxMissedTicks
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 70;
	
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_YieldWhenWaiting
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 71;
	
	  ;% REALTIME_PARTBONUS_extended_P.EncoderInput1_YieldWhenWaiting
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 72;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_Channels
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PARTBONUS_extended_P.EncoderInput1_Channels
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_RangeMode
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PARTBONUS_extended_P.AnalogOutput1_VoltRange
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_P.StateSpace_InitialCondition
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PARTBONUS_extended_P.Cp_matrixGain_Gain
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PARTBONUS_extended_P.Statefeedback_Gain
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 4;
	
	  ;% REALTIME_PARTBONUS_extended_P.Saturation_UpperSat
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 6;
	
	  ;% REALTIME_PARTBONUS_extended_P.Saturation_LowerSat
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 7;
	
	  ;% REALTIME_PARTBONUS_extended_P.SineWave_Bias
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 8;
	
	  ;% REALTIME_PARTBONUS_extended_P.SineWave_Phase
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 9;
	
	  ;% REALTIME_PARTBONUS_extended_P.Constant_Value
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (REALTIME_PARTBONUS_extended_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_B.rad2deg
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PARTBONUS_extended_B.rads2rpm
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PARTBONUS_extended_B.Saturation
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% REALTIME_PARTBONUS_extended_B.ManualSwitch
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% REALTIME_PARTBONUS_extended_B.thl_meas
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% REALTIME_PARTBONUS_extended_B.TmpSignalConversionAtStateSpaceInport1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (REALTIME_PARTBONUS_extended_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% REALTIME_PARTBONUS_extended_DW.AnalogOutput1_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% REALTIME_PARTBONUS_extended_DW.EncoderInput1_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% REALTIME_PARTBONUS_extended_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2308754547;
  targMap.checksum1 = 3603525762;
  targMap.checksum2 = 3236981476;
  targMap.checksum3 = 151813276;

