Past_House1_MapScripts::
	.byte 0

Past_House1_EventScript_SadGirl::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Past_House1_EventScript_SadGirlPregame
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_SENT_TO_THE_FARM
	switch VAR_RESULT
	case 1, Past_House1_EventScript_SadGirlQuestActivate
	case 2, Past_House1_EventScript_SadGirlQuestActive
	case 3, Past_House1_EventScript_SadGirlQuestReward
	case 4, Past_House1_EventScript_SadGirlQuestComplete
	release
	end

Past_House1_EventScript_SadGirlPregame::
	msgbox Past_House1_Text_SadGirlWaaa, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Past_House1_EventScript_SadGirlQuestActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_SAD_GIRL_INSIDE, DIR_WEST, Name_Farmgirl, Past_House1_Text_SadGirlWaaa
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_WhatsWrong
	speak LOCALID_PAST_SAD_GIRL_INSIDE, VAR_0x8005, Name_Farmgirl, Past_House1_Text_SadGirlMyPoorOxen
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Past_House1_Text_LookerItsOkay
	speak LOCALID_PAST_SAD_GIRL_INSIDE, VAR_0x8005, Name_Farmgirl, Past_House1_Text_SadGirlExplaining
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Past_House1_Text_LookerDontWorry
	speak LOCALID_PAST_SAD_GIRL_INSIDE, VAR_0x8005, Name_Farmgirl, Past_House1_Text_SadGirlThankYou
	startquest QUEST_SENT_TO_THE_FARM
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Past_House1_EventScript_SadGirlQuestActive::
	faceplayer
	speakername Name_Farmgirl
	msgbox Past_House1_Text_SadGirlEveryRemedy, MSGBOX_DEFAULT
	closemessage
	release
	end

Past_House1_EventScript_SadGirlQuestReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_PAST_SAD_GIRL_INSIDE, VAR_0x8005, Name_Farmgirl, Past_House1_Text_SadGirlIsThatMedicine
	removeitem ITEM_FULL_RESTORE
	speakername NULL
	playfanfare MUS_OBTAIN_TMHM
	message Past_House1_Text_LookerGaveFullRestores
	waitmessage
	waitfanfare
	speak LOCALID_PAST_SAD_GIRL_INSIDE, VAR_0x8005, Name_Farmgirl, Past_House1_Text_SadGirlIllGoGiveThese
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Past_House1_EventScript_SadGirlExitHouse1
	call_if_eq VAR_FACING, DIR_SOUTH, Past_House1_EventScript_SadGirlExitHouse1
	call_if_eq VAR_FACING, DIR_WEST, Past_House1_EventScript_SadGirlExitHouse2
	playse SE_EXIT
	removeobject LOCALID_PAST_SAD_GIRL_INSIDE
	waitse
	clearflag FLAG_HIDE_PAST_SAD_GIRL_OUTSIDE
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Past_House1_EventScript_SadGirlExitHouse1::
	applymovement LOCALID_PAST_SAD_GIRL_INSIDE, Past_House1_Movement_SadGirlExitHouse1
	waitmovement 0
	return

Past_House1_EventScript_SadGirlExitHouse2::
	applymovement LOCALID_PAST_SAD_GIRL_INSIDE, Past_House1_Movement_SadGirlExitHouse2
	waitmovement 0
	return

Past_House1_Movement_SadGirlExitHouse1:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Past_House1_Movement_SadGirlExitHouse2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

Past_House1_EventScript_SadGirlQuestComplete::
	faceplayer
	speakername Name_Farmgirl
	call_if_set FLAG_HIDE_TAUROS, Past_House1_EventScript_SadGirlIsTaurosHappy
	call_if_set FLAG_HIDE_MILTANK, Past_House1_EventScript_SadGirlIsMiltankHappy
	closemessage
	release
	end

Past_House1_EventScript_SadGirlIsTaurosHappy::
	msgbox Past_House1_Text_SadGirlIsTaurosHappy, MSGBOX_DEFAULT
	return

Past_House1_EventScript_SadGirlIsMiltankHappy::
	msgbox Past_House1_Text_SadGirlIsMiltankHappy, MSGBOX_DEFAULT
	return

Past_House1_Text_SadGirlWaaa:
	.string "Waaaah!\p"
	.string "Waaaah!\p"
	.string "…Snivel…\n"
	.string "…Hic…$"

Past_House1_Text_SadGirlMyPoorOxen:
	.string "Oh, sir!\p"
	.string "My poor oxen!\p"
	.string "My oxen whom I cradled and raised and\n"
	.string "spent ages rearing to adulthood…\p"
	.string "My oxen are gravely sick!\p"
	.string "Waaaah!$"
	
Past_House1_Text_LookerItsOkay:
	.string "Hey, it's going to be okay.\n"
	.string "What's wrong? Can I help?$"

Past_House1_Text_SadGirlExplaining:
	.string "…Hic…\p"
	.string "My beloved Tauros, Torin, and Miltank,\n"
	.string "Moomoo, caught an odd affliction two\l"
	.string "weeks ago, and their health has\l"
	.string "deteriorated substantially since then!\p"
	.string "My parents and I have tried everything\n"
	.string "to heal them -\l"
	.string "herbal remedies, bloodletting…\p"
	.string "We even consulted Camilla and the elder\n"
	.string "for solutions!\p"
	.string "But nothing is working!\p"
	.string "…Snivel…$"

Past_House1_Text_LookerDontWorry:
    .string "Don't worry. I will find some way to make\n"
	.string "your cattle feel better.$"

Past_House1_Text_SadGirlThankYou:
	.string "Ohhhh…\p"
	.string "Thank you…\p"
	.string "I do not know what else there is to try,\n"
	.string "though… I am at my wit's end…$"

Past_House1_Text_SadGirlEveryRemedy:
	.string "Every remedy we could think of,\n"
	.string "every medical practice available to us,\l"
	.string "even our local leader cannot bring them\l"
	.string "to good health!\p"
	.string "Why can't my Pokémon feel better?\p"
	.string "Waaaah!$"

Past_House1_Text_SadGirlIsThatMedicine:
	.string "Oh? Did you find something I could give\n"
	.string "to the poor ailing oxen?\p"
	.string "Please, let me see!$"

Past_House1_Text_LookerGaveFullRestores:
	.string "Looker handed over the Full Restores!$"

Past_House1_Text_SadGirlIllGoGiveThese:
	.string "Wow, these are unlike anything I have\n"
	.string "ever seen before!\p"
	.string "I will go apply these ointments to Torin\n"
	.string "and Moomoo!\p"
	.string "Sir, please meet me in the west meadow,\n"
	.string "posthaste!$"

Past_House1_Text_SadGirlIsTaurosHappy:
	.string "Make sure to give Torin lots of love!\n"
	.string "He's a really special boy!$"

Past_House1_Text_SadGirlIsMiltankHappy:
	.string "Make sure to give Moomoo lots of love!\n"
	.string "She's a really special girl!$"