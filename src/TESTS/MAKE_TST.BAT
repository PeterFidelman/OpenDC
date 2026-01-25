echo off

c88 arith a
if errorlevel 1 goto stop
c88 compare a
if errorlevel 1 goto stop

c88 arith
if errorlevel 1 goto stop
c88 compare
if errorlevel 1 goto stop

bind arith
if errorlevel 1 goto stop
bind compare
if errorlevel 1 goto stop

arith
compare

:stop
