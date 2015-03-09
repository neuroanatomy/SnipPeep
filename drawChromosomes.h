-(void)drawChr:(int)index inRect:(NSRect)rect
{
	NSBezierPath	*bp;
	NSRect	r;
	float	min,max,w,z;
	float	*chr;
	float	chr1[64*2]={	 72.562,0xE3, 76.781,0x8E, 82.688,0xE3, 86.062,0x8E, 89.438,0xE3,
							 96.188,0x55,102.938,0xE3,110.531,0x8E,117.281,0xE3,124.875,0x8E,
							129.094,0xE3,133.312,0x8E,137.531,0xE3,146.812,0x8E,155.25 ,0xE3,
							159.469,0x39,168.75 ,0xE3,178.031,0x55,183.094,0xE3,186.469,0x55,
							201.656,0xE3,203.344,0x00,231.188,0xE3,237.938,0x39,245.531,0xE3,
							249.75 ,0x39,259.031,0xE3,264.094,0x00,273.375,0xE3,281.812,0x55,
							290.25 ,0xE3,293.625,0x55,298.688,0xE3,299.531,0xFF,306.281,0xFF,
							313.031,0x00,340.031,0xE3,350.156,0x55,353.531,0xE3,360.281,0x55,
							362.812,0xE3,367.875,0x55,370.406,0xE3,379.688,0x55,383.062,0xE3,
							389.812,0x39,394.031,0xE3,399.938,0x55,407.531,0xE3,417.656,0x00,
							426.938,0xE3,432.844,0x00,442.969,0xE3,458.156,0x8E,465.75 ,0xE3,
							470.812,0x00,489.375,0xE3,490.219,0x8E,495.281,0xE3,502.031,0x55,
							509.625,0xE3,513.000,0x39,526.500,0xE3,536.625,0x00};
	float	chr2[63*2]={	 67.500,0xE3, 75.938,0x55, 81.000,0xE3, 91.969,0x39,100.406,0xE3,
							104.625,0x39,113.906,0xE3,120.656,0x8E,124.875,0xE3,129.094,0x39,
							137.531,0xE3,141.750,0x55,147.656,0xE3,159.469,0x00,169.594,0xE3,
							172.969,0x00,185.625,0xE3,190.688,0x55,203.344,0xE3,207.562,0x55,
							210.094,0xE3,213.469,0x00,229.500,0xE3,243.000,0xFF,248.062,0xFF,
							252.281,0xE3,264.938,0x55,270.844,0xE3,273.375,0x8E,277.594,0xE3,
							286.875,0x55,296.156,0xE3,302.906,0x55,318.094,0xE3,323.156,0x8E,
							327.375,0xE3,331.594,0x00,342.562,0xE3,346.781,0x00,354.375,0xE3,
							356.062,0x8E,357.750,0xE3,366.188,0x39,375.469,0xE3,383.062,0x39,
							394.875,0xE3,410.906,0x55,415.969,0xE3,420.188,0x39,432.844,0xE3,
							437.062,0x39,448.031,0xE3,460.688,0x55,464.906,0xE3,471.656,0x00,
							482.625,0xE3,494.438,0x39,502.031,0xE3,503.719,0x00,513.000,0xE3,
							521.438,0x55,524.812,0xE3,536.625,0x00};
	float	chr3[63*2]={	 67.500,0x55, 75.938,0xE3, 80.156,0x55, 87.750,0xE3, 94.500,0x8E,
							 97.031,0xE3,102.094,0x00,123.188,0xE3,129.938,0x39,140.062,0xE3,
							142.594,0x55,153.562,0xE3,160.312,0x39,170.438,0xE3,172.125,0x55,
							172.969,0xE3,188.156,0x8E,189.000,0xE3,195.750,0x55,205.031,0xE3,
							217.688,0x55,236.250,0xE3,242.156,0x39,259.875,0xE3,264.094,0x39,
							272.531,0xE3,277.594,0xFF,283.500,0xFF,286.875,0x00,302.062,0xE3,
							306.281,0x8E,308.812,0xE3,313.031,0x39,320.625,0xE3,324.844,0x55,
							332.438,0xE3,337.500,0x39,346.781,0xE3,351.000,0x39,357.750,0xE3,
							361.969,0x8E,367.875,0xE3,376.312,0x8E,386.438,0xE3,390.656,0x8E,
							397.406,0xE3,406.688,0x00,421.031,0xE3,428.625,0x55,435.375,0xE3,
							439.594,0x55,443.812,0xE3,446.344,0x00,465.750,0xE3,473.344,0x39,
							484.312,0xE3,491.906,0x39,500.344,0xE3,504.562,0x8E,508.781,0xE3,
							513.000,0x39,523.125,0xE3,536.625,0x00};
	float	chr4[48*2]={	 67.500,0xE3, 75.094,0x8E, 80.156,0xE3, 94.500,0x55,104.625,0xE3,
							113.062,0x39,124.031,0xE3,135.844,0x00,154.406,0xE3,167.906,0x55,
							179.719,0xE3,187.312,0xFF,191.531,0xFF,195.750,0xE3,212.625,0x00,
							230.344,0xE3,240.469,0x39,254.812,0xE3,261.562,0x55,270.000,0xE3,
							274.219,0x8E,280.969,0xE3,283.500,0x39,297.844,0xE3,301.219,0x39,
							310.500,0xE3,318.938,0x55,332.438,0xE3,347.625,0x39,363.656,0xE3,
							371.250,0x55,383.906,0xE3,389.812,0x00,410.062,0xE3,415.125,0x8E,
							422.719,0xE3,429.469,0x8E,437.906,0xE3,448.031,0x00,463.219,0xE3,
							470.812,0x00,485.156,0xE3,490.219,0x39,500.344,0xE3,503.719,0x00,
							515.531,0xE3,526.500,0x8E,536.625,0x00};
	float	chr5[46*2]={	72.562,0xE3,83.531,0x8E,87.75,0xE3,93.656,0x55,111.375,0xE3,
							119.812,0x00,132.469,0xE3,135.844,0x00,147.656,0xE3,161.156,0x8E,
							171.281,0xE3,181.406,0x55,189.844,0xFF,194.906,0xFF,202.5,0xE3,
							223.594,0x39,234.562,0xE3,236.25,0x39,243,0xE3,248.062,0x55,
							260.719,0xE3,268.312,0x55,280.969,0xE3,285.188,0x00,307.969,0xE3,
							322.312,0x00,336.656,0xE3,340.875,0x00,353.531,0xE3,358.594,0x55,
							362.812,0xE3,367.875,0x00,383.906,0xE3,399.094,0x00,407.531,0xE3,
							420.188,0x8E,429.469,0xE3,439.594,0x39,450.562,0xE3,463.219,0x55,
							471.656,0xE3,482.625,0x00,502.031,0xE3,514.688,0x8E,525.656,0xE3,
							536.625,0x00};

	float	chr6[49*2]={	67.5,0xE3,73.406,0x8E,78.469,0xE3,86.906,0x55,96.188,0xE3,
							97.875,0x8E,104.625,0xE3,109.688,0x39,131.625,0xE3,139.219,0x55,
							149.344,0xE3,155.25,0x8E,159.469,0xE3,168.75,0x8E,178.875,0xE3,
							191.531,0x00,207.562,0xE3,211.781,0x00,224.438,0xE3,227.812,0xFF,
							233.719,0xFF,241.312,0xE3,242.156,0x00,259.875,0xE3,275.906,0x55,
							297.844,0xE3,300.375,0x55,307.969,0xE3,320.625,0x00,338.344,0xE3,
							341.719,0x00,355.219,0xE3,380.531,0x39,388.969,0xE3,393.188,0x00,
							414.281,0xE3,416.812,0x39,425.25,0xE3,427.781,0x55,438.75,0xE3,
							449.719,0x39,459.844,0xE3,467.438,0x39,476.719,0xE3,486,0x55,
							494.438,0xE3,508.781,0x55,518.906,0xE3,536.625,0x00};

	float	chr7[45*2]={	67.5,0xE3,73.406,0x8E,81,0xE3,88.594,0x00,107.156,0xE3,
							112.219,0x00,124.875,0xE3,140.906,0x55,150.188,0xE3,161.156,0x39,
							172.969,0xE3,178.031,0x39,195.75,0xE3,205.031,0x39,214.312,0xE3,
							217.688,0x39,226.969,0xE3,237.094,0xFF,242.156,0xFF,248.062,0xE3,
							262.406,0x55,279.281,0xE3,296.156,0x00,322.312,0xE3,327.375,0x39,
							335.812,0xE3,340.875,0x39,356.906,0xE3,375.469,0x55,380.531,0xE3,
							383.906,0x39,405,0xE3,413.438,0x39,424.406,0xE3,432.844,0x39,
							442.125,0xE3,448.875,0x8E,451.406,0xE3,459,0x55,473.344,0xE3,
							489.375,0x39,502.875,0xE3,517.219,0x8E,524.812,0xE3,536.625,0x00};

	float	chr8[41*2]={	67.5,0xE3,74.25,0x39,87.75,0xE3,108,0x00,129.094,0xE3,
							142.594,0x55,155.25,0xE3,162.844,0x39,190.688,0xE3,194.062,0x8E,
							195.75,0xE3,205.875,0xFF,212.625,0xFF,221.906,0xE3,229.5,0x39,
							237.094,0xE3,245.531,0x55,265.781,0xE3,267.469,0x55,279.281,0xE3,
							286.031,0x55,293.625,0xE3,304.594,0x00,318.938,0xE3,324.844,0x39,
							340.031,0xE3,346.781,0x00,367.031,0xE3,385.594,0x8E,393.188,0xE3,
							407.531,0x39,421.875,0xE3,426.938,0x00,444.656,0xE3,449.719,0x55,
							460.688,0xE3,475.875,0x55,489.375,0xE3,505.406,0x39,516.375,0xE3,
							536.625,0x00};

	float	chr9[44*2]={	67.5,0xE3,75.094,0x8E,82.688,0xE3,97.875,0x39,114.75,0xE3,
							123.188,0x8E,129.094,0xE3,134.156,0x00,152.719,0xE3,161.156,0x00,
							177.188,0xE3,189,0x8E,194.906,0xE3,201.656,0x55,209.25,0xE3,
							223.594,0xFF,240.469,0xFF,269.156,0x00,301.219,0xE3,302.906,0x8E,
							310.5,0xE3,312.188,0x55,332.438,0xE3,335.812,0x55,346.781,0xE3,
							355.219,0x55,367.031,0xE3,372.094,0x8E,378.844,0xE3,387.281,0x8E,
							395.719,0xE3,407.531,0x00,426.094,0xE3,436.219,0x8E,448.031,0xE3,
							458.156,0x39,475.875,0xE3,488.531,0x8E,500.344,0xE3,510.469,0x8E,
							511.312,0xE3,518.906,0x8E,523.969,0xE3,536.625,0x00};

	float	chr10[43*2]={	72.562,0xE3,82.688,0x8E,85.219,0xE3,95.344,0x39,114.75,0xE3,
							131.625,0x39,140.906,0xE3,142.594,0x39,151.031,0xE3,155.25,0x55,
							169.594,0xE3,180.562,0x8E,190.688,0xE3,205.875,0xFF,210.938,0xFF,
							216.844,0xE3,230.344,0x8E,244.688,0xE3,255.656,0x00,282.656,0xE3,
							294.469,0x00,317.25,0xE3,328.219,0x55,337.5,0xE3,353.531,0x00,
							373.781,0xE3,379.688,0x39,390.656,0xE3,395.719,0x55,408.375,0xE3,
							413.438,0x55,421.875,0xE3,425.25,0x8E,432,0xE3,434.531,0x00,
							455.625,0xE3,466.594,0x39,480.938,0xE3,489.375,0x55,494.438,0xE3,
							509.625,0x55,519.75,0xE3,536.625,0x00};

	float	chr11[37*2]={	72.562,0xE3,81.844,0x55,109.688,0xE3,116.438,0x55,128.25,0xE3,
							146.812,0x00,162,0xE3,166.219,0x39,179.719,0xE3,198.281,0x00,
							222.75,0xE3,241.312,0x39,249.75,0xFF,254.812,0xFF,267.469,0x39,
							278.438,0xE3,284.344,0x8E,290.25,0xE3,303.75,0x8E,311.344,0xE3,
							316.406,0x55,330.75,0xE3,337.5,0x00,367.031,0xE3,376.312,0x00,
							391.5,0xE3,406.688,0x00,423.562,0xE3,426.094,0x00,452.25,0xE3,
							461.531,0x55,470.812,0xE3,489.375,0x55,498.656,0xE3,512.156,0x55,
							522.281,0xE3,536.625,0x00};

	float	chr12[42*2]={	77.625,0xE3,88.594,0x8E,96.188,0xE3,112.219,0x39,121.5,0xE3,
							129.094,0x00,146.812,0xE3,151.031,0x00,168.75,0xE3,173.812,0x55,
							183.938,0xE3,192.375,0xFF,200.812,0xFF,204.188,0x00,232.031,0xE3,
							242.156,0x8E,245.531,0xE3,261.562,0x8E,269.156,0xE3,272.531,0x39,
							290.25,0xE3,297.844,0x55,306.281,0xE3,319.781,0x39,334.969,0xE3,
							350.156,0x00,372.938,0xE3,381.375,0x00,394.031,0xE3,406.688,0x39,
							424.406,0xE3,432.844,0x55,450.562,0xE3,459.844,0x8E,461.531,0xE3,
							469.125,0x55,477.562,0xE3,482.625,0x55,491.062,0xE3,509.625,0x55,
							523.969,0xE3,536.625,0x00};

	float	chr13[37*2]={	62.438,0x00,78.469,0x7F,97.031,0x00,118.125,0xFF,129.094,0xFF,
							139.219,0xE3,154.406,0x8E,163.688,0xE3,172.969,0x8E,178.031,0xE3,
							191.531,0x55,199.125,0xE3,206.719,0x39,226.125,0xE3,246.375,0x8E,
							253.125,0xE3,253.969,0x55,265.781,0xE3,279.281,0x00,302.062,0xE3,
							313.875,0x39,329.062,0xE3,341.719,0x00,361.969,0xE3,370.406,0x55,
							378,0xE3,385.594,0x00,421.875,0xE3,431.156,0x00,452.25,0xE3,
							465.75,0x8E,469.969,0xE3,480.094,0x00,493.594,0xE3,502.031,0x00,
							515.531,0xE3,536.625,0x00};

	float	chr14[33*2]={	62.438,0x00,75.938,0x7F,91.969,0x00,123.188,0xFF,131.625,0xFF,
							147.656,0xE3,167.906,0x00,204.188,0xE3,214.312,0x55,221.062,0xE3,
							226.969,0x00,245.531,0xE3,254.812,0x00,277.594,0xE3,295.312,0x8E,
							304.594,0xE3,311.344,0x39,334.969,0xE3,347.625,0x55,361.125,0xE3,
							371.25,0x55,387.281,0xE3,411.75,0x00,430.312,0xE3,437.062,0x00,
							459,0xE3,465.75,0x8E,475.875,0xE3,487.688,0x55,509.625,0xE3,
							518.062,0x55,521.438,0xE3,536.625,0x00};

	float	chr15[33*2]={	62.438,0x00,79.312,0x7F,99.562,0x00,129.094,0xFF,142.594,0xFF,
							149.344,0xE3,172.969,0x55,183.938,0xE3,194.906,0x55,199.125,0xE3,
							210.938,0x39,241.312,0xE3,254.812,0x8E,258.188,0xE3,264.094,0x39,
							287.719,0xE3,303.75,0x39,326.531,0xE3,332.438,0x8E,352.688,0xE3,
							369.562,0x8E,369.562,0xE3,371.25,0x8E,394.875,0xE3,407.531,0x8E,
							414.281,0xE3,421.875,0x55,437.906,0xE3,454.781,0x55,473.344,0xE3,
							497.812,0x55,517.219,0xE3,536.625,0x00};

	float	chr16[26*2]={	72.562,0xE3,105.469,0x55,126.562,0xE3,137.531,0x55,149.344,0xE3,
							159.469,0x55,179.719,0xE3,185.625,0x55,216.844,0xE3,252.281,0xFF,
							272.531,0xFF,285.188,0x00,310.5,0xE3,340.031,0x55,356.906,0xE3,
							368.719,0x00,413.438,0xE3,435.375,0x55,437.062,0xE3,455.625,0x39,
							480.938,0xE3,492.75,0x55,504.562,0xE3,519.75,0x8E,528.188,0xE3,
							536.625,0x00};

	float	chr17[25*2]={	72.562,0xE3,93.656,0x55,112.219,0xE3,138.375,0x39,166.219,0xE3,
							202.5,0xFF,203.344,0xFF,209.25,0xE3,242.156,0x55,280.969,0xE3,
							282.656,0x8E,295.312,0xE3,319.781,0x8E,336.656,0xE3,352.688,0x39,
							395.719,0xE3,399.938,0x39,416.812,0xE3,425.25,0x55,435.375,0xE3,
							453.094,0x39,475.875,0xE3,497.812,0x8E,502.031,0xE3,536.625,0x00};

	float	chr18[21*2]={	77.625,0xE3,95.344,0x55,120.656,0xE3,129.094,0x8E,143.438,0xE3,
							170.438,0xFF,174.656,0xFF,182.25,0xE3,218.531,0x00,264.938,0xE3,
							291.938,0x39,329.906,0xE3,357.75,0x39,391.5,0xE3,405.844,0x55,
							421.875,0xE3,437.906,0x00,469.125,0xE3,480.938,0x8E,507.938,0xE3,
							536.625,0x00};

	float	chr19[20*2]={	72.562,0xE3,122.344,0x8E,164.531,0xE3,172.969,0x8E,189.844,0xE3,
							216.844,0x00,266.625,0xFF,280.125,0xFF,291.938,0x00,342.562,0xE3,
							365.344,0x8E,385.594,0xE3,388.125,0x8E,420.188,0xE3,436.219,0x8E,
							464.062,0xE3,491.062,0x8E,502.031,0xE3,518.906,0x8E,536.625,0x00};

	float	chr20[21*2]={	62.438,0xE3,100.406,0x39,130.781,0xE3,152.719,0x39,197.438,0xE3,
							223.594,0x8E,232.031,0xE3,257.344,0xFF,268.312,0xFF,278.438,0xE3,
							302.062,0x8E,319.781,0xE3,344.25,0x39,374.625,0xE3,378,0x8E,
							410.062,0xE3,436.219,0x39,475.875,0xE3,486.844,0x55,502.031,0xE3,
							536.625,0x00};

	float	chr21[15*2]={	62.438,0x00,91.969,0x7F,125.719,0x00,163.688,0xFF,186.469,0xFF,
							195.75,0xE3,216.844,0x00,293.625,0xE3,323.156,0x39,370.406,0xE3,
							412.594,0x55,432.844,0xE3,452.25,0x55,480.938,0xE3,536.625,0x00};

	float	chr22[17*2]={	62.438,0x00,91.125,0x7F,125.719,0x00,154.406,0xFF,174.656,0xFF,
							217.688,0xE3,258.188,0x8E,270.844,0xE3,294.469,0x55,329.062,0xE3,
							353.531,0x55,405,0xE3,437.062,0x55,469.125,0xE3,511.312,0x55,
							522.281,0xE3,536.625,0x00};

	float	chrX[41*2]={	72.562,0xE3,85.219,0x55,90.281,0xE3,101.25,0x55,124.031,0xE3,
							129.938,0x55,137.531,0xE3,146.812,0x00,160.312,0xE3,167.062,0x00,
							184.781,0xE3,199.125,0x39,214.312,0xE3,221.062,0x8E,236.25,0xE3,
							242.156,0xFF,250.594,0xFF,267.469,0xE3,267.469,0x55,275.062,0xE3,
							288.562,0x55,293.625,0xE3,300.375,0x00,325.688,0xE3,330.75,0x00,
							347.625,0xE3,352.688,0x39,367.031,0xE3,379.688,0x55,383.062,0xE3,
							403.312,0x39,422.719,0xE3,434.531,0x00,461.531,0xE3,463.219,0x8E,
							472.5,0xE3,485.156,0x39,491.906,0xE3,497.812,0x00,513,0xE3,
							536.625,0x00};

	float	chrY[12*2]={	72.562,0xE3,86.062,0x55,98.719,0xE3,162.844,0xFF,163.688,0xFF,
							172.969,0xE3,187.312,0x55,225.281,0xE3,243.844,0x55,276.75,0xE3,
							291.094,0x00,536.625,0x00};

	int		nbands;
	int		i,c;
	
	switch(index)
	{
		case 1:		chr=chr1; nbands=64;	break;
		case 2:		chr=chr2; nbands=63;	break;
		case 3:		chr=chr3; nbands=63;	break;
		case 4:		chr=chr4; nbands=48;	break;
		case 5:		chr=chr5; nbands=46;	break;
		case 6:		chr=chr6; nbands=49;	break;
		case 7:		chr=chr7; nbands=45;	break;
		case 8:		chr=chr8; nbands=41;	break;
		case 9:		chr=chr9; nbands=44;	break;
		case 10:	chr=chr10; nbands=43;	break;
		case 11:	chr=chr11; nbands=37;	break;
		case 12:	chr=chr12; nbands=42;	break;
		case 13:	chr=chr13; nbands=37;	break;
		case 14:	chr=chr14; nbands=33;	break;
		case 15:	chr=chr15; nbands=33;	break;
		case 16:	chr=chr16; nbands=26;	break;
		case 17:	chr=chr17; nbands=25;	break;
		case 18:	chr=chr18; nbands=21;	break;
		case 19:	chr=chr19; nbands=20;	break;
		case 20:	chr=chr20; nbands=21;	break;
		case 21:	chr=chr21; nbands=15;	break;
		case 22:	chr=chr22; nbands=17;	break;
		case 23:	chr=chrX; nbands=41;	break;
		case 24:	chr=chrY; nbands=12;	break;
	}
	min=chr[0];
	max=chr[2*(nbands-1)];
	z=rect.size.width/(max-min);
	c=0;
	for(i=0;i<nbands-1;i++)
	{
		w=(chr[2*(i+1)]-chr[2*i]);
		r=(NSRect){(chr[2*i]-min)*z+rect.origin.x,rect.origin.y,w*z,rect.size.height};
		if(chr[2*i+1]==0xFF && c==0)
		{
			bp=[NSBezierPath bezierPath];
			[bp moveToPoint:r.origin];
			[bp lineToPoint:(NSPoint){r.origin.x+r.size.width,r.origin.y+r.size.height/2.0}];
			[bp lineToPoint:(NSPoint){r.origin.x,r.origin.y+r.size.height}];
			[bp moveToPoint:r.origin];
			c=1;
			[[NSColor orangeColor] set];
			[bp fill];
		}
		else
		if(chr[2*i+1]==0xFF && c==1)
		{
			bp=[NSBezierPath bezierPath];
			[bp moveToPoint:(NSPoint){r.origin.x,r.origin.y+r.size.height/2.0}];
			[bp lineToPoint:(NSPoint){r.origin.x+r.size.width,r.origin.y}];
			[bp lineToPoint:(NSPoint){r.origin.x+r.size.width,r.origin.y+r.size.height}];
			[bp moveToPoint:(NSPoint){r.origin.x,r.origin.y+r.size.height/2.0}];
			c=2;
			[[NSColor orangeColor] set];
			[bp fill];
		}
		else
		{
			[[NSColor colorWithDeviceWhite:chr[2*i+1]/255.0 alpha:1.0] set];
			NSRectFill(r);
		}
	}
}