#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}
#Put your test case here

eval spawn [lrange $argv 0 end]

expect "What is the operation?" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "add\r"
send "4\r"
send "5\r"
expect "9" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

eval spawn [lrange $argv 0 end]
expect "What is the operation?" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "subtract\r"
send "6\r"
send "2\r"
expect "4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
