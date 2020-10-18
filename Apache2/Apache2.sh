#!/bin/bash

if(whiptail --title "Apache" --yes-button "START" --no-button "STOP" --yesno "Selecione START para iniciar o servidor Apache ou então STOP para parar o servidor.
--[Acesso no browser: localhost/SeuAqruivo.php]" 10 60) then
	/etc/init.d/apache2 start
	whiptail --title "Apache" --msgbox "Servidor Apache 2.4 em Execução" 10 60
	
else
	/etc/init.d/apache2 stop
	whiptail --title "Apache" --msgbox "Servidor Apache 2.4 Parado" 10 60
fi

