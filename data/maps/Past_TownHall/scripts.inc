Past_TownHall_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Past_TownHall_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Past_TownHall_OnFrame
	.byte 0

Past_TownHall_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 6, Past_TownHall_EventScript_LookerWakesUpSetup
	call_if_eq VAR_CUTSCENE_STATE, 7, Past_TownHall_EventScript_PreMythSetup
	end

Past_TownHall_EventScript_LookerWakesUpSetup::
	setflag FLAG_SYS_PREVENT_MAP_FADE
	setobjectxyperm LOCALID_TOWNHALL_ESTELLA 1, 4
	setobjectmovementtype LOCALID_TOWNHALL_ESTELLA, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_TOWNHALL_ANABEL 2, 4
	setobjectmovementtype LOCALID_TOWNHALL_ANABEL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_TOWNHALL_CAMILLA, 3, 3
	setobjectmovementtype LOCALID_TOWNHALL_CAMILLA, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_TOWNHALL_HAPPINY, 3, 2
	setobjectmovementtype LOCALID_TOWNHALL_HAPPINY, MOVEMENT_TYPE_FACE_LEFT
	return

Past_TownHall_EventScript_PreMythSetup::
	setobjectxyperm LOCALID_TOWNHALL_CAMILLA, 16, 5
	setobjectmovementtype LOCALID_TOWNHALL_CAMILLA, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_TOWNHALL_HAPPINY, 16, 4
	setobjectmovementtype LOCALID_TOWNHALL_HAPPINY, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_TOWNHALL_ESTELLA, 15, 6
	setobjectmovementtype LOCALID_TOWNHALL_ESTELLA, MOVEMENT_TYPE_FACE_UP
	return

Past_TownHall_OnFrame:
	map_script_2 VAR_CUTSCENE_STATE, 6, Past_TownHall_EventScript_LookerWakesUp
	.2byte 0

Past_TownHall_EventScript_LookerWakesUp::
	lockall
	delay 100
	msgbox Past_TownHall_Text_Dots, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 150
	msgbox Past_TownHall_Text_LookerUgh, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 30
	msgbox Past_TownHall_Text_SoundsLikeHesMoving, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 30
	msgbox Past_TownHall_Text_AnabelPleaseWakeUp, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 100
	msgbox Past_TownHall_Text_Dots, MSGBOX_DEFAULT
	delay 48
	closemessage
	delay 100
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadescreen FADE_FROM_BLACK
	delay 48
	msgbox Past_TownHall_Text_LookerWakingUp, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_ANABEL, Common_Movement_WalkInPlaceFasterUp
	msgbox Past_TownHall_Text_AnabelDontSpeak, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_WalkInPlaceFasterLeft
	msgbox Past_TownHall_Text_CamillaYouAreNotTheFirst, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_ANABEL, Common_Movement_WalkInPlaceFasterUp
	msgbox Past_TownHall_Text_AnabelThisIsCamilla, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_ESTELLA, Common_Movement_WalkInPlaceFasterUp
	msgbox Past_TownHall_Text_LostGirl, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_WalkInPlaceFasterDown
	msgbox Past_TownHall_Text_CamillaProsperity, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_ESTELLA, Common_Movement_WalkInPlaceFasterUp
	msgbox Past_TownHall_Text_LostGirl2, MSGBOX_DEFAULT
	applymovement LOCALID_TOWNHALL_ANABEL, Common_Movement_WalkInPlaceFasterUp
	msgbox Past_TownHall_Text_AnabelCamillaToldMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceLeft
	msgbox Past_TownHall_Text_LookerSure, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	delay 150
	msgbox Past_TownHall_Text_Dots, MSGBOX_DEFAULT
	delay 40
	closemessage
	removeobject LOCALID_TOWNHALL_ANABEL
	removeobject LOCALID_TOWNHALL_CAMILLA
	removeobject LOCALID_TOWNHALL_HAPPINY
	removeobject LOCALID_TOWNHALL_ESTELLA
	clearflag FLAG_HIDE_PAST_TOWN_HALL_ESTELLA
	setobjectxyperm LOCALID_TOWNHALL_CAMILLA, 16, 5
	setobjectmovementtype LOCALID_TOWNHALL_CAMILLA, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_TOWNHALL_HAPPINY, 16, 4
	setobjectmovementtype LOCALID_TOWNHALL_HAPPINY, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_TOWNHALL_ESTELLA, 15, 6
	setobjectmovementtype LOCALID_TOWNHALL_ESTELLA, MOVEMENT_TYPE_FACE_UP
	delay 50
	addobject LOCALID_TOWNHALL_ESTELLA
	addobject LOCALID_TOWNHALL_CAMILLA
	addobject LOCALID_TOWNHALL_HAPPINY
	delay 50
	fadescreen FADE_FROM_BLACK
	delay 60
	msgbox Past_TownHall_Text_LookerWakingUpAgain, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight, MSGBOX_DEFAULT
	waitmovement 0
	setvar VAR_CUTSCENE_STATE, 7
	releaseall
	end

Past_TownHall_EventScript_Camilla::
	lock
	faceplayer
	msgbox Past_TownHall_Text_CamillaIWillLookAfterHer, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_TownHall_EventScript_Estella::
	msgbox Past_TownHall_Text_Estella, MSGBOX_NPC
	end

Past_TownHall_EventScript_Happiny::
	playmoncry SPECIES_HAPPINY, CRY_MODE_NORMAL
	msgbox Past_TownHall_Text_Happiny, MSGBOX_NPC
	end

Past_TownHall_Text_Happiny:
	.string "Happi happiii!$"

Past_TownHall_Text_Estella:
	.string "um, um!\p"
	.string "i'll stay here until you're\n"
	.string "back from the forest sir!$"

Past_TownHall_Text_CamillaIWillLookAfterHer:
	.string "Mr. Looker, I am glad to see you\n"
	.string "up on your feet so soon!\p"
	.string "Miss Anabel is waiting for you at\n"
	.string "the Shrine of Prosperity in the\l"
	.string "eastern wood.\p"
	.string "Please join her in speaking with\n"
	.string "our village elder at your earliest\l"
	.string "convenience!\p"
	.string "I will look after Estella in your\n"
	.string "absense!$"

Past_TownHall_Text_LookerWakingUpAgain:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

Past_TownHall_Text_SoundsLikeHesMoving:
	.string "???: Miss Anabel, your companion's\n"
	.string "moving again!$"

Past_TownHall_Text_AnabelPleaseWakeUp:
	.string "Anabel: Looker, please wake up!\p"
	.string "I know you're strong enough to not\n"
	.string "let a few bruises do you in!$"

Past_TownHall_Text_LookerWakingUp:
	.string "Looker: Anabel…\n"
	.string "You're safe…?$"

Past_TownHall_Text_AnabelDontSpeak:
	.string "Anabel: Don't worry about me,\n"
	.string "you're a mess right now!\p"
	.string "You collapsed right at the town's\n"
	.string "entrance!\p"
	.string "Get this - we're actually a few\n"
	.string "hundred years in the past!$"

Past_TownHall_Text_CamillaYouAreNotTheFirst:
	.string "???: Yes, you three are not the\n"
	.string "first to be sent here, nor do I\l"
	.string "believe you will be the last!\p"
	.string "For some reason, the Spirit of\n"
	.string "Peace has an affinity for our\l"
	.string "particular point in history.\p"
	.string "My name is Camilla.\n"
	.string "Pleased to make your acquaintance!$"

Past_TownHall_Text_AnabelThisIsCamilla:
	.string "Anabel: Camilla here acts as both\n"
	.string "doctor and mayor to the city! \p"
	.string "She and Happiny nursed me back to\n"
	.string "full health a few days ago -\l"
	.string "they're dang good at what they do.$"

Past_TownHall_Text_LostGirl:
	.string "Estella: um, um, um!\p"
	.string "sorry for causing so much trouble,\n"
	.string "sir!\p"
	.string "grammy taught me bad things happen\n"
	.string "when our peace and posterity--$"

Past_TownHall_Text_CamillaProsperity:
	.string "Camilla: Prosperity, not posterity!$"

Past_TownHall_Text_LostGirl2:
	.string "Estella: posperity are messed with!\p"
	.string "i had to do something to save them, but\n"
	.string "then i was attacked by strong pokémon…\p"
	.string "now i'm here!$"

Past_TownHall_Text_AnabelCamillaToldMe:
	.string "Anabel: Camilla told me she came\n"
	.string "a week ago today.\p"
	.string "Kinda crazy, right?\n"
	.string "There's more though.\p"
	.string "Once you're feeling all rested up,\n"
	.string "Come see me at the east forest\l"
	.string "shrine, the Shrine of Prosperity.\p"
	.string "It seems we'll learn more about why\n"
	.string "Porto Bella is out of whack from the\l"
	.string "village orator there.$"

Past_TownHall_Text_LookerSure:
	.string "Looker: Sure…\p"
	.string "So long as everyone's safe…\p"
	.string "… … …\n"
	.string "… … …$"

Past_TownHall_Text_LookerUgh:
	.string "Looker: Ugh…$"

Past_TownHall_Text_Dots:
	.string "… … …\n"
	.string "… … …$"