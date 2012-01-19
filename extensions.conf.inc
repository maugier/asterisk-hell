
[torture]
exten => s,1,Background(torture1)
exten => 1,1,Goto(tortureend,s,1)
exten => 2,1,Goto(torture2,s,1)
exten => 3,1,Goto(torture2,s,1)
exten => s,2,Goto(torture,s,1)

[torture2]
exten => s,1,Background(torture2)
exten => _X,1,Goto(tortureend,s,1)
exten => s,2,Goto(torture,s,1)

[tortureend]
exten => s,1,Playback(tortureend)
exten => s,2,Hangup()


