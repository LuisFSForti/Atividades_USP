#Altere a pasta abaixo para a pasta do seu projeto
set pasta C:/Users/Luis/Documents/Escola/Atividades_USP/Sistemas_Digitais/Quarta_Parte/projeto/leonardo
set encoding Binary
set resource_sharing TRUE
set report_delay_detail short
set report_area_format_style %6.2f
set exclude_gates {}
load_library scl05u

set_working_dir $pasta
read -technology "scl05u" -dont_elaborate { ./decod24.v }
read -technology "scl05u" -dont_elaborate { ./mux41.v }
read -technology "scl05u" -dont_elaborate { ./registrador.v }
read -technology "scl05u" -dont_elaborate { ./banco_de_registradores.v }

set x 8
#for {set x 2} {$x<=64} {set x [expr {$x * 2}]} {

elaborate banco_de_registradores -parameters Size=$x

optimize .work.banco_de_registradores .INTERFACE -target scl05u -macro -area -effort quick -hierarchy auto 
optimize_timing .work.banco_de_registradores .INTERFACE 

report_area area_$x.txt -cell_usage -all_leafs 
report_delay  delay_$x.txt -num_paths 1 -critical_paths -clock_frequency
auto_write -format Verilog -downto PRIMITIVES banco_de_registradores_$x.v
#}