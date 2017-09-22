#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here

expect "What is the id?: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0101\r"
expect "Name: Angel Perez, Semester: 6" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

eval spawn [lrange $argv 0 end]
expect "What is the id?: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0202\r"
expect "Name: Jesus Lopez, Semester: 4" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

eval spawn [lrange $argv 0 end]
expect "What is the id?: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0000\r"
expect "No such student." {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
