echo off

c88 arith
if errorlevel 1 goto stop
c88 compare
if errorlevel 1 goto stop
c88 compare1
if errorlevel 1 goto stop
c88 compare2
if errorlevel 1 goto stop
c88 compare3
if errorlevel 1 goto stop
c88 compare4
if errorlevel 1 goto stop
c88 compare5
if errorlevel 1 goto stop
c88 compare6
if errorlevel 1 goto stop
c88 compare7
if errorlevel 1 goto stop
c88 compare8
if errorlevel 1 goto stop

bind arith
if errorlevel 1 goto stop
bind compare
if errorlevel 1 goto stop
bind compare1
if errorlevel 1 goto stop
bind compare2
if errorlevel 1 goto stop
bind compare3
if errorlevel 1 goto stop
bind compare4
if errorlevel 1 goto stop
bind compare5
if errorlevel 1 goto stop
bind compare6
if errorlevel 1 goto stop
bind compare7
if errorlevel 1 goto stop
bind compare8
if errorlevel 1 goto stop

arith
compare
compare1
compare2
compare3
compare4
compare5
compare6
compare7
compare8

:stop
