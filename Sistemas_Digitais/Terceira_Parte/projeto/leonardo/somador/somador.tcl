#Altere a pasta abaixo para a pasta do seu projeto
set pasta C:/Users/Luis/Documents/Escola/Atividades_USP/Sistemas_Digitais/Terceira_Parte/projeto/leonardo/somador
set encoding Binary
set resource_sharing TRUE
set report_delay_detail short
set exclude_gates {}
load_library scl05u

set_working_dir $pasta
read -technology "scl05u" -dont_elaborate { ./somador.v }

set x 8
#for {set x 2} {$x<=128} {set x [expr {$x * 2}]} {

elaborate somador -parameters Size=$x

optimize .work.somador.INTERFACE -target scl05u -macro -area -effort quick -hierarchy auto 
optimize_timing .work.somador.INTERFACE 

report_area area_$x.txt -cell_usage -all_leafs 
report_delay  delay_$x.txt -num_paths 1 -critical_paths -clock_frequency
auto_write -format Verilog -downto PRIMITIVES somador_$x.v
#}