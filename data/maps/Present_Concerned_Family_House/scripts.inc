Present_Concerned_Family_House_MapScripts::
	.byte 0

Present_ConcernedFamilyHouse_EventScript_LookerINeedToThink::
	lockall
	speakername Name_Looker
	msgbox Present_ConcernedFamilyHouse_Text_LookerINeedToThink, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

Present_ConcernedFamilyHouse_EventScript_Mom::
	msgbox Present_ConcernedFamilyHouse_Text_MomMyBaby, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_Dad::
	lock
	faceplayer
	returnqueststate QUEST_SAVE_ESTELLA
	switch VAR_RESULT
	case 3, Present_ConcernedFamilyHouse_EventScript_DadRewardQuest
	case 4, Present_ConcernedFamilyHouse_EventScript_DadCompletedQuest
	end

Present_ConcernedFamilyHouse_EventScript_DadRewardQuest::
	call Script_GetNPCFacingDirection
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_ConcernedFamilyHouse_Text_LookerDaughterBackHomeSafe
	speak LOCALID_CONCERNEDFAMILY_DAD, VAR_0x8005, Name_Relieved_Dad, Present_ConcernedFamilyHouse_Text_DadThankYou
	giveitem ITEM_FIRE_STONE
	closemessage
	copyvar VAR_0x8004, VAR_0x8005 @Dad is 8004, Grandma is 8005
	copyvar VAR_0x8003, VAR_FACING @0x8003 is Looker's original direction
	getplayerxy VAR_0x8000, VAR_0x8001
	call_if_eq VAR_0x8000, 11, Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerNorth
	call_if_eq VAR_0x8000, 12, Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerWest
	call Script_GetNPCFacingDirection
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, VAR_0x8005, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaDidYouLearn
	speak LOCALID_PLAYER, VAR_FACING, Name_Looker, Present_ConcernedFamilyHouse_Text_LookerILearnedAbout
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, VAR_0x8005, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaSoTheLegendsAreTrue
	call_if_eq VAR_0x8000, 11, Present_ConcernedFamilyHouse_EventScript_DadSpeakLookerNorth
	call_if_eq VAR_0x8000, 12, Present_ConcernedFamilyHouse_EventScript_DadSpeakLookerWest
	speak LOCALID_CONCERNEDFAMILY_GRANDMA, VAR_0x8005, Name_Grandma, Present_ConcernedFamilyHouse_Text_GrandmaSigh
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1
	clearflag FLAG_HIDE_CELEBI_SOCIETY_GRANDMA
	warpdoor MAP_PRESENT_CELEBI_SOCIETY, 2, 8
	delay 48
	end

Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerNorth::
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Present_ConcernedFamilyHouse_Movement_MoveGrandmaToLookerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 5
	return

Present_ConcernedFamilyHouse_EventScript_MoveGrandmaToLookerWest::
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Present_ConcernedFamilyHouse_Movement_MoveGrandmaToLookerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 5
	return

Present_ConcernedFamilyHouse_EventScript_DadSpeakLookerNorth::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Common_Movement_FaceUp
	speak LOCALID_CONCERNEDFAMILY_DAD, DIR_WEST, Name_Relieved_Dad, Present_ConcernedFamilyHouse_Text_DadWillYouQuitIt
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	return

Present_ConcernedFamilyHouse_EventScript_DadSpeakLookerWest::
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_CONCERNEDFAMILY_GRANDMA, Common_Movement_FaceLeft
	speak LOCALID_CONCERNEDFAMILY_DAD, DIR_SOUTH, Name_Relieved_Dad, Present_ConcernedFamilyHouse_Text_DadWillYouQuitIt
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
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
	msgbox Present_ConcernedFamilyHouse_Text_EstellaDidntBelieveMe, MSGBOX_NPC
	end

Present_ConcernedFamilyHouse_EventScript_Grandma::
	end

Present_ConcernedFamilyHouse_Text_LookerDaughterBackHomeSafe:
	.string "I see your daughter has made it\n"
	.string "home. I presume she came with Anabel?$"

Present_ConcernedFamilyHouse_Text_DadThankYou:
	.string "Oh yes, thank you Looker!\p"
	.string "When she came home, we gave her a\n"
	.string "stern talking-to about going out\l"
	.string "to the forest on her own.\p"
	.string "Though I felt it went in one ear\n"
	.string "and out the other…\p"
	.string "Regardless, please take this as\n"
	.string "a token of our appreciation!$"

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
	.string "This isn't a good place to talk\n"
	.string "about this…\p"
	.string "Here, follow me.$"

Present_ConcernedFamilyHouse_Text_MomMyBaby:
	.string "My baby's back!\p"
	.string "Oh, Mr. Looker, thank you so so\n"
	.string "much for bringing her home safe!$"

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