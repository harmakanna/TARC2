Past_TownHall_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Past_TownHall_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, Past_TownHall_OnFrame
	.byte 0

Past_TownHall_OnTransition:
	call_if_eq VAR_CUTSCENE_STATE, 8, Past_TownHall_EventScript_LookerWakesUpSetup
	call_if_eq VAR_CUTSCENE_STATE, 9, Past_TownHall_EventScript_PreMythSetup
	call_if_eq VAR_CUTSCENE_STATE, 10, Past_TownHall_EventScript_PreMythSetup
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
	map_script_2 VAR_CUTSCENE_STATE, 8, Past_TownHall_EventScript_LookerWakesUp
	.2byte 0

Past_TownHall_EventScript_LookerWakesUp::
	lockall
	clearflag FLAG_SYS_NO_MUSIC_ON_TRANSITION
	delay 100
	msgbox Past_TownHall_Text_Dots, MSGBOX_DEFAULT
	closemessage
	delay 150
	speakername Name_Looker
	message Past_TownHall_Text_LookerUgh
	delay 60
	closemessage
	delay 30
	speakername Name_Unknown
	message Past_TownHall_Text_SoundsLikeHesMoving
	delay 80
	closemessage
	delay 30
	speakername Name_Anabel
	message Past_TownHall_Text_AnabelPleaseWakeUp
	waitmessage
	delay 60
	message Past_TownHall_Text_AnabelIKnowYoureStrongEnough
	waitmessage
	delay 80
	closemessage
	delay 60
	msgbox Past_TownHall_Text_Dots, MSGBOX_DEFAULT
	closemessage
	delay 100
	clearflag FLAG_SYS_PREVENT_MAP_FADE
	fadedefaultbgm
	playbgm MUS_DP_ETERNA_NIGHT, FALSE
	fadescreen FADE_FROM_BLACK
	delay 48
	speakername Name_Looker
	msgbox Past_TownHall_Text_LookerWakingUp, MSGBOX_DEFAULT
	speak LOCALID_TOWNHALL_ANABEL, DIR_NORTH, Name_Anabel, Past_TownHall_Text_AnabelDontSpeak
	speak LOCALID_TOWNHALL_CAMILLA, DIR_WEST, Name_Unknown, Past_TownHall_Text_CamillaMyName
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Past_TownHall_Text_LookerTheTown
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	msgbox Past_TownHall_Text_LookerWhereAreWe, MSGBOX_DEFAULT
	speak LOCALID_TOWNHALL_ANABEL, DIR_NORTH, Name_Anabel, Past_TownHall_Text_AnabelYouSlowpoke
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_TOWNHALL_CAMILLA, DIR_WEST, Name_Camilla, Past_TownHall_Text_CamillaYouAreNotTheFirst
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	speak LOCALID_TOWNHALL_ESTELLA, DIR_NORTH, Name_Estella, Past_TownHall_Text_LostGirl
	speak LOCALID_TOWNHALL_CAMILLA, DIR_SOUTH, Name_Camilla, Past_TownHall_Text_CamillaProsperity
	speak LOCALID_TOWNHALL_ESTELLA, DIR_NORTH, Name_Estella, Past_TownHall_Text_LostGirl2
	speak LOCALID_TOWNHALL_ANABEL, DIR_NORTH, Name_Anabel, Past_TownHall_Text_AnabelCamillaToldMe
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceLeft
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Past_TownHall_Text_LookerSure
	closemessage
	fadescreen FADE_TO_BLACK
	delay 100
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
	@speakername Name_Looker
	@msgbox Past_TownHall_Text_LookerWakingUpAgain, MSGBOX_DEFAULT
	@closemessage
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight, MSGBOX_DEFAULT
	waitmovement 0
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	clearflag FLAG_HIDE_TAUROS
	clearflag FLAG_HIDE_MILTANK
	setflag FLAG_SYS_B_DASH
	setvar VAR_CUTSCENE_STATE, 9
	releaseall
	end

Past_TownHall_EventScript_Camilla::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Past_TownHall_EventScript_CamillaPreGame
	returnqueststate QUEST_HOMEGROWN_REMEDIES
	goto_if_eq VAR_RESULT, 2, Past_TownHall_EventScript_CamillaGiveRevivalHerb
	checkitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, TRUE, Past_TownHall_EventScript_CamillaAcceptEstellaCandy
	returnqueststate QUEST_SENT_TO_THE_FARM
	goto_if_eq VAR_RESULT, 2, Past_TownHall_EventScript_CamillaCannotHealBulls
	returnqueststate QUEST_WITH_MUCH_GRATITUDE
	goto_if_eq VAR_RESULT, 3, Past_TownHall_EventScript_CamillaCantWaitToDigIn
	speakername Name_Camilla
	msgbox Past_TownHall_Text_CamillaPleaseLetMeKnow, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_EventScript_CamillaGiveRevivalHerb::
	call Script_GetNPCFacingDirection
	speak LOCALID_TOWNHALL_CAMILLA, VAR_0x8005, Name_Camilla, Past_TownHall_Text_CamillaWhatIsIt
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	speak LOCALID_TOWNHALL_CAMILLA, VAR_0x8005, Name_Camilla, Past_TownHall_Text_CamillaOhHereYouGo
	speakername NULL
	giveitem ITEM_REVIVAL_HERB
	questmenu QUEST_MENU_SET_REWARD, QUEST_HOMEGROWN_REMEDIES
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ThankYou
	speak LOCALID_TOWNHALL_CAMILLA, VAR_0x8005, Name_Camilla, Past_TownHall_Text_CamillaOfCourse
	closemessage
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_EventScript_CamillaAcceptEstellaCandy::
	call Script_GetNPCFacingDirection
	playse SE_PIN
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_ExclamationMark
	waitmovement 0
	delay 50
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Past_TownHall_Text_LookerAGiftForYou
	removeitem ITEM_RARE_CANDY
	speakername NULL
	msgbox Past_TownHall_Text_LookerHandedOverTheRareCandy, MSGBOX_DEFAULT
	speak LOCALID_TOWNHALL_CAMILLA, VAR_0x8005, Name_Camilla, Past_TownHall_Text_CamillaWhyAGift
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_WillDo
	questmenu QUEST_MENU_SET_REWARD, QUEST_WITH_MUCH_GRATITUDE
	closemessage
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	removeitem ITEM_RARE_CANDY
	release
	end

Past_TownHall_EventScript_CamillaCannotHealBulls::
	call Script_GetNPCFacingDirection
	speak LOCALID_TOWNHALL_CAMILLA, VAR_0x8005, Name_Camilla, Past_TownHall_Text_CamillaWhatIsIt
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SoHeresTheThing
	speak LOCALID_TOWNHALL_CAMILLA, VAR_0x8005, Name_Camilla, Past_TownHall_CamillaICannotHelp
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_Hmm
	closemessage
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_EventScript_CamillaCantWaitToDigIn::
	speakername Name_Camilla
	msgbox Past_TownHall_Text_CamillaICantWaitToDigIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
	
Past_TownHall_EventScript_CamillaPreGame::
	speakername Name_Camilla
	msgbox Past_TownHall_Text_CamillaIWillLookAfterHer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWNHALL_CAMILLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_EventScript_Estella::
	lock
	faceplayer
	speakername Name_Estella
	msgbox Past_TownHall_Text_Estella, MSGBOX_DEFAULT
	closemessage	
	applymovement LOCALID_TOWNHALL_ESTELLA, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_EventScript_Happiny::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HAPPINY, CRY_MODE_NORMAL
	msgbox Past_TownHall_Text_Happiny, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_TOWNHALL_HAPPINY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_EventScript_ApprenticeNurse::
	speakername Name_Past_Nurse
	msgbox Past_TownHall_Text_ApprenticeNurse, MSGBOX_NPC
	end

Past_TownHall_EventScript_Comfey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_COMFEY, CRY_MODE_NORMAL
	msgbox Past_TownHall_Text_Comfey, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Past_TownHall_EventScript_SailorLeft::
	lock
	speakername Name_Sailor
	msgbox Past_TownHall_Text_SailorLeft, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_TownHall_EventScript_SailorBottom::
	speakername Name_Sailor
	msgbox Past_TownHall_Text_SailorBottom MSGBOX_NPC
	end

Past_TownHall_EventScript_SailorRight::
	lock
	faceplayer
	speakername Name_Sailor
	msgbox Past_TownHall_Text_SailorRight, MSGBOX_DEFAULT
	applymovement LOCALID_PAST_RIGHT_SAILOR, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_SELECT
	msgbox Past_TownHall_Text_SailorAnother, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PAST_RIGHT_SAILOR, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Past_TownHall_Text_SailorLeft:
	.string "Camilla! Bring another round of drinks\n"
	.string "for the table!$"

Past_TownHall_Text_SailorBottom:
	.string "Uuuuurp…\p"
	.string "No more… I'm so plastered already…$"

Past_TownHall_Text_SailorRight:
	.string "Aye! Our ship got wrecked by a gnarly\n"
	.string "tornado a good while back!\p"
	.string "We saw some strange green frog man at\n"
	.string "the top of the tornado, we think…?\p"
	.string "No matter! If it meant we washed up on\n"
	.string "the shores of Porta Bella, it was\l"
	.string "worth it!$"

Past_TownHall_Text_SailorAnother:
	.string "Camilla, another drink!$"

Past_TownHall_Text_ApprenticeNurse:
	.string "Oooooh…\p"
	.string "My mother had recommended I apprentice\n"
	.string "with Camilla as a nurse and I started\l"
	.string "last week…\p"
	.string "I believed it to be a great idea at the\n"
	.string "time, but I did not know I was so\l"
	.string "squeamish to blood and mucus…\p"
	.string "But I cannot let Camilla and my mother\n"
	.string "down now…$"

Past_TownHall_Text_CamillaPleaseLetMeKnow:
	.string "Please, should you ever need help in\n"
	.string "our era, let me know!$"

Past_TownHall_Text_LookerAGiftForYou:
	.string "Camilla!\p"
	.string "I have a gift for you from Estella.$"

Past_TownHall_Text_CamillaWhyAGift:
	.string "Oh wow! A box of candies!\p"
	.string "Sweets like these are exceedingly rare\n"
	.string "and sought-after, but I suppose their\l"
	.string "abundance in your time makes sense.\p"
	.string "Please, give Estella my regards!$"

Past_TownHall_Text_CamillaICantWaitToDigIn:
	.string "I look forward to digging into these\n"
	.string "wonderful-smelling candies!\p"
	.string "Please, give Estella my thanks!$"

Past_TownHall_Text_LookerIndeedFromEstella:
	.string "Indeed. These sweets are a thank-you\n"
	.string "gift from Estella.$"

Past_TownHall_Text_Happiny:
	.string "Happi happiii!$"

Past_TownHall_Text_LookerHandedOverTheRareCandy:
	.string "Looker handed over Estella's gift\n"
	.string "to Camilla!$"

Past_TownHall_Text_Estella:
	.string "um, um!\p"
	.string "i'll stay here until you're back from\n"
	.string "the forest sir!$"

Past_TownHall_Text_CamillaIWillLookAfterHer:
	.string "Mr. Looker, I am glad to see you up on\n"
	.string "your feet so soon!\p"
	.string "Miss Anabel is waiting for you at the\n"
	.string "Shrine of Prosperity in the eastern\l"
	.string "forest.\p"
	.string "Please join her in speaking with the\n"
	.string "village elder at your earliest\l"
	.string "opportunity!\p"
	.string "I will look after Estella in your\n"
	.string "absense!$"

Past_TownHall_Text_LookerWakingUpAgain:
	.string "… … …\n"
	.string "… … …\p"
	.string "… … …\n"
	.string "… … …$"

Past_TownHall_Text_SoundsLikeHesMoving:
	.string "Miss Anabel, your companion's\n"
	.string "moving again!$"

Past_TownHall_Text_AnabelPleaseWakeUp:
	.string "Looker, please wake up!$"

Past_TownHall_Text_AnabelIKnowYoureStrongEnough:
	.string "I know you're strong enough to not\n"
	.string "let a simple fall do you in!$"

Past_TownHall_Text_LookerWakingUp:
	.string "Anabel…\n"
	.string "You're safe…?$"

Past_TownHall_Text_AnabelDontSpeak:
	.string "Don't worry about me, you're a mess\n"
	.string "right now!\p"
	.string "You collapsed right at the town's\n"
	.string "entrance, you know!$"

Past_TownHall_Text_CamillaMyName:
	.string "I am glad to finally see you awake!\p"
	.string "My name is Camilla, mayor and head\n"
	.string "doctor of Porta Bella!\p"
	.string "Pleased to make your acquaintance!$"

Past_TownHall_Text_LookerTheTown:
	.string "Porta Bella…?\p"
	.string "This isn't Porta Bella…$"

Past_TownHall_Text_LookerWhereAreWe:
	.string "Anabel, where are we?$"

Past_TownHall_Text_AnabelYouSlowpoke:
	.string "Wow, you Slowpoke! You haven't figured\n"
	.string "it out yet?\p"
	.string "We're a few hundred years in the past!$"

Past_TownHall_Text_CamillaYouAreNotTheFirst:
	.string "Hahahaha!\p"
	.string "You three are not the first to be sent\n"
	.string "here, nor do I believe you will be\l"
	.string "the last!\p"
	.string "For some reason, the Spirit of Peace\n"
	.string "has an affinity for our particular\l"
	.string "point in history.$"
	
Past_TownHall_Text_LostGirl:
	.string "um, um, um!\p"
	.string "sorry for causing so much trouble,\n"
	.string "sir!\p"
	.string "grammy taught me bad things happen\n"
	.string "when our peace and posterity--$"

Past_TownHall_Text_CamillaProsperity:
	.string "Prosperity, not posterity!$"

Past_TownHall_Text_LostGirl2:
	.string "posperity are messed with!\p"
	.string "i had to do something to save them, but\n"
	.string "then i was attacked by strong pokémon…$"

Past_TownHall_Text_AnabelCamillaToldMe:
	.string "Camilla told me she came one week ago\n"
	.string "today.\p"
	.string "Kinda crazy, right?\n"
	.string "There's more though.\p"
	.string "Once you're feeling all rested up, come\n"
	.string "see me at the east forest shrine, the\l"
	.string "Shrine of Prosperity.\p"
	.string "It seems we'll learn more about why\n"
	.string "Porta Bella is out of whack from the\l"
	.string "village elder there.$"

Past_TownHall_Text_LookerSure:
	.string "Sure…\p"
	.string "So long as everyone's safe…\p"
	.string "… … …\n"
	.string "… … …$"

Past_TownHall_Text_LookerUgh:
	.string "Ugh…$"

Past_TownHall_Text_Dots:
	.string "… … …\n"
	.string "… … …$"

Past_TownHall_Text_CamillaWhatIsIt:
	.string "Oh? Looker?\p"
	.string "What brings you here?$"

Past_TownHall_Text_CamillaOhHereYouGo:
	.string "Oh, is that it?\p"
	.string "Here you are. These roots are used in\n"
	.string "our tea to promote vitality among our\l"
	.string "oldest residents.\p"
	.string "If the man is feeling as bad as you say\n"
	.string "he is, however, it might be best for him\l"
	.string "to eat it raw.$"

Past_TownHall_CamillaICannotHelp:
	.string "Oh, our poor Tauros and Miltank…\n"
	.string "I am sorry, but I cannot help them.\p"
	.string "I have tried everything I have, but\n"
	.string "their condition just will not improve…\p"
	.string "Perhaps the remedy for their ailment\n"
	.string "does not exist in our time?$"

Past_TownHall_Text_CamillaOfCourse:
	.string "Of course! I am always happy to help.$"

Past_TownHall_Text_Comfey:
	.string "Oomfey~!$"
