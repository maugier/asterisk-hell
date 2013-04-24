
[torture]
; Bonjour et bienvenue au support technique xolus.net.
; Pour une requête de dépannage, faites le 1.
; Pour un appel de nature commerciale, faites le 2.
; Pour un appel d'autre nature, faites le 3

exten => s,1,Background(torture1)
exten => 1,1,Goto(torture3,s,1)  ; service technique
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
exten => 2,1,Goto(torture4,s,1)
exten => 3,1,Goto(torturesondage,s,1)
exten => 6,1,Goto(torturecom,s,1)
exten => _X,1,Goto(tortureend,s,1)
exten => s,2,Goto(torture,s,1) ; attendu trop longtemps ? retour a la racine TROLOLOLO

[torture3]

; Bienvenue au service technique
; Pour un problème dans votre zone DNS, faites le 1
; Pour un problème sur votre domaine XMPP, faites le 2
; Pour un problème sur votre lien VPN, faites le 3
; Pour un problème d'autre nature, faites le 4
exten => s,1,Background(torture3)
exten => _X,1,Goto(tortureend2,s,1)

[torture4]
; Bienvenue au service des relations publiques.
; Si vous représentez le parti pirate, faites le 1
; Si vous représentez le POP, faites le 2
; Si vous représentez la ligue des tessinois, faites le 3
; Si vous représentez le parti évangélique, faites le 4
; Si vous représentez le parti chrétien social, faites le 5
; Si vous représentez l'Union Démocratique Fédérale, faites le 6
; Si vous représentez le parti bourgeois démocratique, faites le 7
; Si vous représentez le parti vert libéral, faites le 8
; Pour les autres partis, faites le 9
exten => s,1,Background(torture4)
exten => 9,1,Goto(torture5,s,1)
exten => _X,1,Goto(tortureend,s,1)
exten => s,2,Goto(torture,s,1)

[torture5]
; Si vous représentez le parti écologiste, faites le 1
; Si vous représentez le parti démocrate-chrétien, faites le 2
; Si vous représentez le parti libéral-radical, faites le 3
; Si vous représentez le parti socialiste, faites le 4
; Si vous représentez l'UDC, faites le 5
exten => s,1,Background(torture5)
exten => _X,1,Goto(tortureend,s,1)
exten => s,2,Goto(torture,s,1)

[torturesondage]
; Merci d'avoir appelé notre serveur vocal. Pour des raisons
; d'assurance qualité, veuillez répondre a ces quelques questions.
; Comment évaluez-vous la qualité des voix de ce menu vocal ?
; Si vous trouvez les voix excellentes, faites le 1
; Si vous trouvez les voix bonnes, faites le 2
; Si vous trouvez les voix acceptables, faites le 3
; Si vous trouvez les voix médiocres, faites le 4
; Si vous trouvez les voix mauvaises, faites le 5;
exten => s,1,Background(torturesondage)
exten => _X,1,Goto(torturesondage2,s,1)
exten => s,2,Goto(torture,s,1)

[torturesondage2]
; Merci. Comment évaluez-vous la qualité des textes de ce serveur vocal ?
; (bis repetita)

[torturecom]
; Veuillez indiquer le secteur d'activité de votre entreprise
; Pour le secteur agricole et alimentaire, faites le 1
; Pour le secteur siderurgique et minier, faites le 2
; Pour le secteur textile, faites le 3
; Pour le secteur aeronautique, faites le 4
; Pour le secteur pétrolier, faites le 5
; Pour le secteur électronique, faites le 6
; Pour le secteur bancaire, faites le 7
; Pour le secteur de la grande distribution, faites le 8
; Pour les autres secteurs, faites le 9

[tortureend]
; Nous sommes navrés de ne pouvoir accéder a votre requête pour l'instant.
; Merci de rappeler plus tard.
exten => s,1,Playback(tortureend)
exten => s,2,Hangup()


[tortureend2]
; Un message d'alerte automatique a été envoyé. Merci de rappeler plus tard.
exten => s,1,Playback(tortureend2)
exten => s,2,Hangup()


