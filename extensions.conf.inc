
[torture]
; Bonjour et bienvenue au support technique xolus.net.
; Pour une requête de dépannage, faites le 1.
; Pour un appel de nature commerciale, faites le 2.
; Pour un appel d'autre nature, faites le 3

exten => s,1,Background(torture1)
exten => 1,1,Goto(tortureend,s,1)  ; pan dans la gueule
exten => 2,1,Goto(torture2,s,1)    ; 2 ou 3 -> menu chiant
exten => 3,1,Goto(torture2,s,1)
exten => s,2,Goto(torture,s,1)     ; attendu trop longtemps ? hop retour au début

[torture2]
; Si vous représentez une organisation caritative, faites le 1
; Si vous représentez une organisation politique, faites le 2
; Si vous représentez un institut de sondage, faites le 3
; Si vous représentez une organisation de recherche de marchés, faites le 5
; Si vous représentez un magazine, faites le 5
; Si vous représentez une organisation commerciale, faites le 6
; Pour les autres, faites le 7

exten => s,1,Background(torture2)
exten => _X,1,Goto(tortureend,s,1)
exten => s,2,Goto(torture,s,1) ; attendu trop longtemps ? retour a la racine TROLOLOLO

[tortureend]
; Nous sommes navrés de ne pouvoir accéder a votre requête pour l'instant.
; Merci de rappeler plus tard.
exten => s,1,Playback(tortureend)
exten => s,2,Hangup()


