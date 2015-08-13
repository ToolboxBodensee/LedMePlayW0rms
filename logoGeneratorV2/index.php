<pre>
void tidl (int value, int y, int x)
{
        if (value == 0)
        {
            
        }
        else if (value == 1)
        {
            _P(x, y, matrix.Color888(10, 10, 0));
        }
        else if (value == 2)
        {
            _P(x, y, matrix.Color888(10, 10, 0));
        }
        else if (value == 3)
        {
            _P(x, y, matrix.Color333(255, 0,   0));
        }

}
<?php

ob_start();

$const = array();

$frames = 26;

echo "void toolboxIntro ()\n";
echo "{\n";
echo "    int delayInMs = 25;\n";

$c = 0;
    


for ($i = $frames; $i > 0; $i -= 2)
{
	echo "    toolboxIntroFrame".$i."();\n";
	if ($i > 1) 
	{
		echo "    tone(audio, NOTE_C5, 100);\n";
		echo "    delay(delayInMs);\n";
		echo "    _C();\n";
	}
	
	if ($i == 2) $i = 3;
}

echo "    delay(5000);\n";

echo "}\n";

for ($i = $frames; $i > 0; --$i)
{
$img = imagecreatefrompng($i.'.png');


	echo "void toolboxIntroFrame".$i." ()\n";
	echo "{\n";


for ($x = 0; $x < 32; ++$x)
{
	$output = array();

	for ($y = 0; $y <= 31; ++$y)
	{
	
		
		$alpha = (imagecolorat($img,$x,$y) & 0x7F000000) >> 24;
		
       // echo $alpha;
       // echo "<br>";
        
        if ($alpha == 127)
        {
        	
        }
        else if ($alpha < 127 && $alpha > 70)
        {
        	echo "    tidl(1, ".$x.", ".$y.");\n";
        }
        else if ($alpha <= 70 && $alpha > 20)
        {
        	echo "    tidl(2, ".$x.", ".$y.");\n";
        }
        else
        {
        	
        	echo "    tidl(3, ".$x.", ".$y.");\n";
        }
        
        
        
	

	}
	
	++$c;
	
	//$const[] =  "    const PROGMEM int PROGMEM t".$c."[32] PROGMEM = { " . implode(', ', $output) . " };\n";
	//echo "    toolboxIntroDrawLogo(t".$c.", ".$x.");\n";
}

	echo "}\n";


}

$c = ob_get_contents();

ob_end_clean();

echo implode("", $const);

echo $c;
