hexcalc
=======

Simple command line tool for hexadecimal (aslo hexadecimal and decimal mixed) calculations

==Purpose
Tool is very usefull when you are working with terminal,
Some times, it's necessary to calculate address and set a breakpoint,
I got crazy openning hex calculator, converting decimals to hexadecimals, calculating, and going back to terminal.
Thats why I wrote this small tool.

==Compilation
<pre>
gcc main.c -o bin/hexcalc
</pre>

==Instalation
<pre>
sudo cp bin/hexcalc /usr/bin
</pre>

or if you're running under osx, see already compiled file  (bin/hexcalc)

==Usage
Conversions
<pre>
$>> hexcalc 12345
evaling: 12345
result : 0x3039
</pre>

Hexadecimal calculations
<pre>
>> hexcalc 0xffffaaaa - 0xaaaa + 0xbbbb 
evaling: 0xffffaaaa-0xaaaa+0xbbbb
result : 0xffffbbbb
</pre>

Mixed calculations
<pre>
>> hexcalc 0xffffaaaa + 1234 - 0xa - 234
evaling: 0xffffaaaa+1234-0xa-234
result : 0xffffae88
</pre>
