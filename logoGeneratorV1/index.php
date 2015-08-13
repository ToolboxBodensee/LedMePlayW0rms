<pre>
<?php

$img = imagecreatefrompng('1.png');

$buffer = array();


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
        	$output[] = 0;
        }
        else if ($alpha < 127 && $alpha > 70)
        {
        	$output[] = 1;
        }
        else if ($alpha <= 70 && $alpha > 20)
        {
        	$output[] = 2;
        }
        else
        {
        	$output[] = 3;
        }
        
        
        
	

	}
	
	echo "int t".$x."[32] = { " . implode(', ', $output) . " };\n";
	$buffer[] = "    toolboxIntroDrawLogo(t".$x.", ".$x.");\n";
}

echo implode('', $buffer);



