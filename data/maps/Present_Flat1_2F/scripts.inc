Present_Flat1_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_Flat1_2F_OnTransition
	.byte 0

Present_Flat1_2F_OnTransition:
	call_if_unset FLAG_HIDE_FLAT1_2F_FAITHFUL_MAN, Present_Flat1_2F_EventScript_SetUpCouple
	end

Present_Flat1_2F_EventScript_SetUpCouple::
	setobjectmovementtype LOCALID_LOVEYDOVEY_WOMAN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_FLAT1_BOYFRIEND, MOVEMENT_TYPE_FACE_UP
	return

Present_Flat1_2F_EventScript_Beauty::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_Flat1_2F_EventScript_BeautyBoyfriendPreGame
	goto_if_set FLAG_BOYFRIEND_WENT_OUT, Present_Flat1_2F_EventScript_BeautyPreGenies
	call Script_GetNPCFacingDirection
	returnqueststate QUEST_FOREVER_FAITHFUL
	switch VAR_RESULT
	case 1, Present_Flat1_2F_EventScript_BeautyPreQuest
	case 2, Present_Flat1_2F_EventScript_BeautyQuest
	@ case 3, Present_Flat1_2F_EventScript_BeautyReward
	case 4, Present_Flat1_2F_EventScript_BeautyBoyfriendPostQuest
	release
	end

Present_Flat1_2F_EventScript_BeautyBoyfriendPreGame::
	speak LOCALID_LOVEYDOVEY_WOMAN, DIR_SOUTH, NULL, Present_Flat1_2F_Text_BeautyPregame
	speak LOCALID_FLAT1_BOYFRIEND, DIR_NORTH, NULL, Present_Flat1_2F_Text_BoyfriendPregame
	playse SE_M_CHARM
	applymovement LOCALID_LOVEYDOVEY_WOMAN, Common_Movement_HeartEmote
	waitse
	playse SE_M_CHARM
	waitse
	playse SE_M_CHARM
	waitse
	delay 35
	speak LOCALID_LOVEYDOVEY_WOMAN, DIR_SOUTH, NULL, Present_Flat1_2F_Text_BeautyPregame
	applymovement LOCALID_LOVEYDOVEY_WOMAN, Common_Movement_FaceLeft
	applymovement LOCALID_FLAT1_BOYFRIEND, Common_Movement_FaceLeft
	closemessage
	release
	end

Present_Flat1_2F_EventScript_BeautyPreGenies::
	faceplayer
	speakername Name_Beauty
	msgbox Present_Flat1_2F_Text_BeautyPreGenies, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LOVEYDOVEY_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Flat1_2F_EventScript_BeautyPreQuest::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_LOVEYDOVEY_WOMAN, VAR_0x8005, Name_Beauty, Present_Flat1_2F_Text_BeautyOhSir
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_IsSomethingWrong
	speak LOCALID_LOVEYDOVEY_WOMAN, VAR_0x8005, Name_Beauty, Present_Flat1_2F_Text_BeautyHesMissing
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_ImOnTheCase
	speak LOCALID_LOVEYDOVEY_WOMAN, VAR_0x8005, Name_Beauty, Present_Flat1_2F_Text_BeautyThankYou
	startquest QUEST_FOREVER_FAITHFUL
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	closemessage
	release
	end

Present_Flat1_2F_EventScript_BeautyQuest::
	speak LOCALID_LOVEYDOVEY_WOMAN, VAR_0x8005, Name_Beauty, Present_Flat1_2F_Text_BeautyThankYou
	closemessage
	release
	end

Present_Flat1_2F_EventScript_BeautyReward::
	setflag FLAG_SYS_DISAPPEAR_QUESTS
	speak LOCALID_LOVEYDOVEY_WOMAN, VAR_0x8005, Name_Beauty, Present_Flat1_2F_Text_BeautyHesBack
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Looker_Text_AllInADaysWork
	speak LOCALID_LOVEYDOVEY_WOMAN, VAR_0x8005, Name_Beauty, Present_Flat1_2F_Text_BeautyWhichMon 
	multichoice MULTI_BEAUTY_GIVEMON, 0, 6, TRUE
	goto_if_eq VAR_RESULT, 0, Present_Flat1_2F_EventScript_BeautyGiveSwanna
	goto_if_eq VAR_RESULT, 1, Present_Flat1_2F_EventScript_BeautyGiveUnfezant
	release
	end

Present_Flat1_2F_EventScript_BeautyFinishQuest::
	completequest QUEST_FOREVER_FAITHFUL
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	release
	end

Present_Flat1_2F_EventScript_BeautyBoyfriendPostQuest::
	speak LOCALID_FLAT1_BOYFRIEND, DIR_NORTH, Name_Boyfriend, Present_Flat1_2F_Text_BoyfriendSoSorry
	speak LOCALID_LOVEYDOVEY_WOMAN, DIR_SOUTH, Name_Beauty, Present_Flat1_2F_Text_BeautySoSorry
	speak LOCALID_FLAT1_BOYFRIEND, DIR_NORTH, Name_Boyfriend, Present_Flat1_2F_Text_BoyfriendOhBaby
	speak LOCALID_LOVEYDOVEY_WOMAN, DIR_SOUTH, Name_Beauty, Present_Flat1_2F_Text_BeautyOhHoney
	closemessage
	release
	end

Present_Flat1_2F_EventScript_Boyfriend::
	lock
	goto_if_unset FLAG_SYS_MAIN_GAME_START, Present_Flat1_2F_EventScript_BeautyBoyfriendPreGame
	returnqueststate QUEST_FOREVER_FAITHFUL
	goto_if_eq VAR_RESULT, 3, Present_Flat1_2F_EventScript_BoyfriendReward
	goto_if_eq VAR_RESULT, 4, Present_Flat1_2F_EventScript_BeautyBoyfriendPostQuest
	release
	end

Present_Flat1_2F_EventScript_BoyfriendReward::
	faceplayer
	speakername Name_Boyfriend
	msgbox Present_Flat1_2F_Text_BoyfriendBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FLAT1_BOYFRIEND, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Present_Flat1_2F_Text_BeautyPregame:
	.string "Baby… Can you run out to the\n"
	.string "grocery store and get us a bunch\l"
	.string "of bananas?\p"
	.string "We're all out…$"

Present_Flat1_2F_Text_BoyfriendPregame:
	.string "Sure sweetcake, lemme just get my\n"
	.string "wallet and keys and I'll be on my\l"
	.string "way soon, just for you!$"

Present_Flat1_2F_Text_BeautyPregame2:
	.string "Oh, baby!\p"
	.string "I looooove you!$"

Present_Flat1_2F_Text_BeautyPreGenies:
	.string "Ohhhh…\p"
	.string "My honey went out to get me some\n"
	.string "bananas not long ago, but he must\l"
	.string "have gotten caught in the storm…$"

Present_Flat1_2F_Text_BeautyOhSir:
	.string "My sweet buns…\n"
	.string "Where could he have gone…$"

Present_Flat1_2F_Text_BeautyHesMissing:
	.string "Oh, mister!\p"
	.string "I asked my boyfriend to go out and\n"
	.string "get us some groceries, but then the\l"
	.string "storm hit!\p"
	.string "I thought he might have run inside\n"
	.string "somewhere to wait it out, but it's\l"
	.string "over and he's still not home…\p"
	.string "Could you please try to find where\n"
	.string "he went? I'm scared…$"

Present_Flat1_2F_Text_BeautyThankYou:
	.string "Thank you!\n"
	.string "I doubt he must have gone far.\p"
	.string "He's not the type to have left the\n"
	.string "city limits, at the very least!$"

Present_Flat1_2F_Text_BoyfriendSoSorry:
	.string "Oh sweetie, I'm so sorry for making\n"
	.string "you worry!\p"
	.string "I got blindsided by that Aromatisse\n"
	.string "and fell under the trap of its\l"
	.string "sweet, hypnotic perfumes!$"

Present_Flat1_2F_Text_BeautySoSorry:
	.string "Oh honey, I'M sorry for asking you\n"
	.string "to go alone for groceries!\p"
	.string "Had I been with you, we could have\n"
	.string "stayed safe in that nasty storm\l"
	.string "together!$"

Present_Flat1_2F_Text_BoyfriendOhBaby:
	.string "Oh sweetie cake!$"

Present_Flat1_2F_Text_BeautyOhHoney:
	.string "Oh honey buns!$"

Present_Flat1_2F_Text_BoyfriendBack:
	.string "I rushed back as soon as you saved\n"
	.string "me, sir!\p"
	.string "Thank you so much for your help!$"

Present_Flat1_2F_Text_BeautyHesBack:
	.string "HE'S BACK!\n"
	.string "MY CUTIE PATOOTIE'S BACK!\p"
	.string "I don't know what you did, but right\n"
	.string "before you came back, Luca ran up\l"
	.string "those stairs and began apologizing\l"
	.string "for being 'unfaithful'?\p"
	.string "I don't care! I'm so happy he's safe!$"

Present_Flat1_2F_Text_BeautyWhichMon:
	.string "It sounds like you went through a lot!\n"
	.string "You're looking to find out who or what\l"
	.string "caused that storm, right?\p"
	.string "Sounds like a tough job!\n"
	.string "Maybe one of my sweet birds could help?\p"
	.string "Feel free to borrow one! They're\n"
	.string "friendly.\p"
	.string "Who would you like to take along?$"