#Altere a pasta abaixo para a pasta do seu projeto
set pasta C:/Users/luis/Documents/Facul/Atividades_USP/Sistemas_Digitais/Segunda_Parte/projeto/leonardo
set encoding Binary
set resource_sharing TRUE
set report_delay_detail short
set report_area_format_style %6.2f
set exclude_gates {}
load_library scl05u

set_working_dir $pasta
read -technology "scl05u" -dont_elaborate { ./mux21.v }
read -technology "scl05u" -dont_elaborate { ./comp.v }
read -technology "scl05u" -dont_elaborate { ./BN.v }
read -technology "scl05u" -dont_elaborate { ./ordenador.v }

#set x 8
for {set x 2} {$x<=64} {set x [expr {$x * 2}]} {

elaborate ordenador -parameters Size=$x

optimize .work.ordenador.INTERFACE -target scl05u -macro -area -effort quick -hierarchy auto 
optimize_timing .work.ordenador.INTERFACE 

report_area area_$x.txt -cell_usage -all_leafs 
report_delay  delay_$x.txt -num_paths 1 -critical_paths -clock_frequency
auto_write -format Verilog -downto PRIMITIVES BN_$x.v
}