Present_Concerned_Family_House_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Concerned_Family_House_OnTransition
	.byte 0

Present_Concerned_Family_House_OnTransition:
	@call_if_set FLAG_SYS_WEATHER_CTRL, Present_Concerned_Family_House_EventScript_ForcePlayMusic
	call_if_unset FLAG_SYS_MAIN_GAME_START, Present_Concerned_Family_House_EventScript_PositionNPCs
	end

Present_Concerned_Family_House_EventScript_PositionNPCs::
	setobjectxyperm LOCALID_CONCERNEDFAMILY_MOM, 8, 4
	setobjectmovementtype LOCALID_CONCERNEDFAMILY_MOM, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_CONCERNEDFAMILY_GRANDMA, 2, 4
	setobjectxyperm LOCALID_CONCERNEDFAMILY_ESTELLA, 4, 4
	return

Present_Concerned_Family_House_EventScript_ForcePlayMusic::
	playbgm MUS_DP_SUNYSHORE_DAY, FALSE
	return

Present_ConcernedFamilyHouse_EventScript_LookerINeedToThink::
	lockall
	speakername Name_Looker
	msgbox Present_ConcernedFamilyHouse_Text_LookerINeedToThink, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

Present_ConcernedFamilyHouse_EventScript_Mom::
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_ConcernedFamilyHouse_EventScript_MomPregame
	msgbox Present_ConcernedFamilyHouse_Text_MomMyBaby, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_MomPregame::
	msgbox Present_ConcernedFamilyHouse_Text_MomPregame, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_Dad::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_ConcernedFamilyHouse_EventScript_DadPregame
	returnqueststate QUEST_SAVE_ESTELLA
	switch VAR_RESULT
	case 3, Present_ConcernedFamilyHouse_EventScript_DadRewardQuest
	case 4, Present_ConcernedFamilyHouse_EventScript_DadCompletedQuest
	end

Present_ConcernedFamilyHouse_EventScript_DadPregame::
	msgbox Present_ConcernedFamilyHouse_Text_DadThatOldWoman, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Present_ConcernedFamilyHouse_EventScript_DadRewardQuest::
	lockall
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_ConcernedFamilyHouse_Text_LookerDaughterBackHomeSafe
	speak LOCALID_CONCERNEDFAMILY_DAD, VAR_0x8005, Name_Relieved_Dad, Present_ConcernedFamilyHouse_Text_DadThankYou
	speakername NULL
	giveitem ITEM_FIRE_STONE
	closemessage
	copyvar VAR_0x8004, VAR_0x8005 @Dad is 8004, Grandma is 8005
	copyvar VAR_0x8003, VAR_FACING @0x8003 is Looker's original direction
	getplayerxy VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 11, Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerNorth
	call_if_eq VAR_0x8000, 12, Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerWest
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 2
	clearflag FLAG_HIDE_CELEBI_SOCIETY_GRANDMA
	warp MAP_PRESENT_CELEBI_SOCIETY, 2, 8
	delay 48
	end

Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerNorth::
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Present_ConcernedFamilyHouse_Movement_MoveGrandmaToLookerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, DIR_EAST, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaDidYouLearn
	speak LOCALID_PLAYER, DIR_WEST, Name_Looker, Present_ConcernedFamilyHouse_Text_LookerILearnedAbout
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, DIR_EAST, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaSoTheLegendsAreTrue
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Common_Movement_FaceUp
	speak LOCALID_CONCERNEDFAMILY_DAD, DIR_SOUTH, Name_Relieved_Dad, Present_ConcernedFamilyHouse_Text_DadWillYouQuitIt
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, DIR_EAST, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaSigh
	return

Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerWest::
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Present_ConcernedFamilyHouse_Movement_MoveGrandmaToLookerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, DIR_NORTH, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaDidYouLearn
	speak LOCALID_PLAYER, DIR_SOUTH, Name_Looker, Present_ConcernedFamilyHouse_Text_LookerILearnedAbout
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, DIR_NORTH, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaSoTheLegendsAreTrue
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Common_Movement_FaceLeft
	speak LOCALID_CONCERNEDFAMILY_DAD, DIR_EAST, Name_Relieved_Dad, Present_ConcernedFamilyHouse_Text_DadWillYouQuitIt
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, DIR_NORTH, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaSigh
	return

Present_ConcernedFamilyHouse_Movement_MoveGrandmaToLookerNorth:
	walk_down
	walk_right
	walk_right
	step_end

Present_ConcernedFamilyHouse_Movement_MoveGrandmaToLookerWest:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Present_ConcernedFamilyHouse_EventScript_DadCompletedQuest::
	msgbox Present_ConcernedFamilyHouse_Text_DadKeepingMyEye, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_ConcernedFamilyHouse_EventScript_Estella::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_ConcernedFamilyHouse_EventScript_EstellaPregame
	faceplayer
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_WITH_MUCH_GRATITUDE
	switch VAR_RESULT
	case 1, Present_ConcernedFamilyHouse_EventScript_EstellaActivate
	case 2, Present_ConcernedFamilyHouse_EventScript_EstellaActive
	case 3, Present_ConcernedFamilyHouse_EventScript_EstellaReward
	case 4, Present_ConcernedFamilyHouse_EventScript_EstellaComplete
	msgbox Present_ConcernedFamilyHouse_Text_EstellaDidntBelieveMe, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_ConcernedFamilyHouse_EventScript_EstellaActivate::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaHi
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_ConcernedFamilyHouse_Text_LookerHiEstella
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaFamilyWontLetMe
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_SureICan
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaThankYouLooker
	speakername NULL
	giveitem ITEM_RARE_CANDY
	startquest QUEST_WITH_MUCH_GRATITUDE
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_ConcernedFamilyHouse_EventScript_EstellaActive::
	speakername Name_Estella
	msgbox Present_ConcernedFamilyHouse_Text_EstellaIHopeSheLikesThem, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_ConcernedFamilyHouse_EventScript_EstellaReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaDidYouBring
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_OfCourse
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaHereHaveThis
	completequest QUEST_WITH_MUCH_GRATITUDE
	setflag FLAG_SWEET_TOOTH_WENT_CRAZY_REWARD
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_ConcernedFamilyHouse_EventScript_EstellaComplete::
	goto_if_unset FLAG_SWEET_TOOTH_WENT_CRAZY_REWARD, Present_ConcernedFamilyHouse_EventScript_EstellaSecretReward
	speakername Name_Estella
	msgbox Present_ConcernedFamilyHouse_Text_EstellaDidntBelieveMe, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_ConcernedFamilyHouse_EventScript_EstellaSecretReward::
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaDidYouBring
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_OfCourse
	playse SE_SELECT
	msgbox Present_ConcernedFamilyHouse_Text_LookerIShouldntTellEstella, MSGBOX_DEFAULT
	speak LOCALID_CONCERNEDFAMILY_ESTELLA, VAR_0x8005, Name_Estella, Present_ConcernedFamilyHouse_Text_EstellaHereHaveThis
	closemessage
	setflag FLAG_SWEET_TOOTH_WENT_CRAZY_REWARD
	release
	end

Present_ConcernedFamilyHouse_EventScript_EstellaPregame::
	msgbox Present_ConcernedFamilyHouse_Text_EstellaPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_ConcernedFamilyHouse_EventScript_Grandma::
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_ConcernedFamilyHouse_EventScript_GrandmaPregame
	speakername Name_Grandma
	msgbox Present_ConcernedFamilyHouse_Text_Grandma, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_GrandmaPregame::
	lock
	msgbox Present_ConcernedFamilyHouse_Text_GrandmaPregame, MSGBOX_DEFAULT
	closemessage
	release
	end

Present_ConcernedFamilyHouse_Text_EstellaDidYouBring:
	.string "hi mr looker! did camilla get like the\n"
	.string "candy gift i got her?$"

Present_ConcernedFamilyHouse_Text_EstellaHereHaveThis:
	.string "yahoo! thank you sooo much mr looker!\p"
	.string "heres a little thank you for you too!$"

Present_ConcernedFamilyHouse_Text_EstellaIHopeSheLikesThem:
	.string "i hope she likes the candies…$"

Present_ConcernedFamilyHouse_Text_EstellaHi:
	.string "hi mr looker!$"

Present_ConcernedFamilyHouse_Text_LookerHiEstella:
	.string "Hi, Estella. Was your trip home okay?$"

Present_ConcernedFamilyHouse_Text_EstellaFamilyWontLetMe:
	.string "it was okay! but now my mom and dad wont\n"
	.string "let me leave the house…\p"
	.string "they dont trust me…\p"
	.string "but i gotta see camilla again!\p"
	.string "i got a thank you gift for her!\p"
	.string "… … …\n"
	.string "… … …\p"
	.string "WAIT!!!\p"
	.string "can you bring it to her please\p"
	.string "itd make me really happy!$"

Present_ConcernedFamilyHouse_Text_EstellaThankYouLooker:
	.string "yahoo!\p"
	.string "thanks mr looker! heres the gift$"

Present_ConcernedFamilyHouse_Text_LookerIShouldntTellEstella:
	.string "(I should probably keep it a secret that\n"
	.string "the candy never reached Camilla…)$"

Present_ConcernedFamilyHouse_Text_MomPregame:
	.string "My mother-in-law worries me sick with the\n"
	.string "bad ideas she gives our baby…\p"
	.string "I've half a mind to send her back home to\n"
	.string "Hoenn on the next cruise out!$"

Present_ConcernedFamilyHouse_Text_EstellaPregame:
	.string "um, um, um!\p"
	.string "so the spirits who were here were bad but\n"
	.string "then there's good spirits in the forest\l"
	.string "who helped us?\p"
	.string "so the forest spirits are friendly and\n"
	.string "who help us if we're in trouble?$"

Present_ConcernedFamilyHouse_Text_Grandma:
	.string "Ohohoho…\p"
	.string "If what my granddaughter says is true,\n"
	.string "you truly met Celebi!\p"
	.string "Please, when we have the time, we must\n"
	.string "talk more of your experiences in the\l"
	.string "forest!$"

Present_ConcernedFamilyHouse_Text_GrandmaPregame:
	.string "Long ago, this city was nothing but\n"
	.string "a stormy wasteland ruled by two spirits.\p"
	.string "These spirits were locked in an endless\n"
	.string "battle.\p"
	.string "Then, one day, their fighting suddenly\n"
	.string "stopped.\p"
	.string "I don't remember the details, but what I\n"
	.string "do remember is that, if there's ever any\l"
	.string "trouble in the city, we must go settle\l"
	.string "things at the Shrines of Peace and\l"
	.string "Prosperity in the forest…$"

Present_ConcernedFamilyHouse_Text_DadThatOldWoman:
	.string "Harumph…\p"
	.string "My kooky old mother's tall tales have\n"
	.string "absolutely enamored my sweet little\l"
	.string "girl…\p"
	.string "I say, there's no value in all this\n"
	.string "hoo-ha about angry spirits and those\l"
	.string "abandoned shrines in the woods!\p"
	.string "We live in the city of progress!$"

Present_ConcernedFamilyHouse_Text_LookerDaughterBackHomeSafe:
	.string "I see your daughter has made it home.\n"
	.string "I presume she came with Anabel?$"

Present_ConcernedFamilyHouse_Text_DadThankYou:
	.string "Oh yes, thank you Looker!\p"
	.string "When she came home, we gave her a\n"
	.string "stern talking-to about going out to\l"
	.string "the forest on her own.\p"
	.string "Though I felt it went in one ear and\n"
	.string "out the other…\p"
	.string "Regardless, please take this as a\n"
	.string "token of our appreciation!$"

Present_ConcernedFamilyHouse_Text_DadKeepingMyEye:
	.string "I'm keeping my eye on my mother…\p"
	.string "She's been putting looney thoughts\n"
	.string "in our childrens' minds since the\l"
	.string "moment they could speak…$"


Present_ConcernedFamilyHouse_Text_GrandmaDidYouLearn:
	.string "Sir, I heard you went to the past to\n"
	.string "find my dear granddaughter.\p"
	.string "Is that true?$"

Present_ConcernedFamilyHouse_Text_LookerILearnedAbout:
	.string "It may be tough to believe, but that\n"
	.string "is correct.$"

Present_ConcernedFamilyHouse_Text_GrandmaSoTheLegendsAreTrue:
	.string "So the legends are true…\p"
	.string "Sir, does that mean you got to meet\n"
	.string "Celebi in the forest?$"

Present_ConcernedFamilyHouse_Text_DadWillYouQuitIt:
	.string "Oh, will you quit it with those old\n"
	.string "fairy tales, you old coot?\p"
	.string "You put poor Estella in danger with\n"
	.string "those silly stories!$"

Present_ConcernedFamilyHouse_Text_GrandmaSigh:
	.string "Mmmmmm…\p"
	.string "This isn't a good place to talk about\n"
	.string "this…\p"
	.string "Here, follow me.$"

Present_ConcernedFamilyHouse_Text_MomMyBaby:
	.string "My baby's back!\p"
	.string "Oh, Mr. Looker, thank you so so much\n"
	.string "for bringing her home safe!$"

Present_ConcernedFamilyHouse_Text_EstellaDidntBelieveMe:
	.string "um, um, um!\p"
	.string "mom and dad didnt believe me when\n"
	.string "i said i went to the past!\p"
	.string "they thought i was pretending!\p"
	.string "only grammy understands me…$"

Present_ConcernedFamilyHouse_Text_LookerINeedToThink:
	.string "Hmm…\p"
	.string "I need some fresh air to think\n"
	.string "about what I just learned…$"