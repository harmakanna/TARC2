Present_Celebi_Society_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Present_CelebiSociety_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Present_CelebiSociety_OnFrame
	.byte 0

Present_CelebiSociety_OnTransition:
	call_if_eq VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 2, Present_CelebiSociety_PreparePostSaveEstella
	end

Present_CelebiSociety_OnFrame:
	map_script_2 VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 2, Present_CelebiSociety_PostSaveEstella
	.2byte 0

Present_CelebiSociety_PreparePostSaveEstella::
	setobjectxyperm LOCALID_CELEBISOCIETY_GRANDMA, 3, 8
	setobjectmovementtype LOCALID_CELEBISOCIETY_GRANDMA, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_PLAYER, MOVEMENT_TYPE_FACE_UP
	return

Present_CelebiSociety_PostSaveEstella::
	lockall
	applymovement LOCALID_PLAYER, Present_CelebiSociety_Movement_LookerWalkUp4
	applymovement LOCALID_CELEBISOCIETY_GRANDMA, Present_CelebiSociety_Movement_GrandmaWalkUp4
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaDidYouMeetCelebi
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CelebiSociety_Text_LookerThatIsCorrect
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaThatIsIncredible
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CelebiSociety_Text_LookerSoYouRevere
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaIWish
	speak LOCALID_PLAYER, DIR_EAST, Name_Looker, Present_CelebiSociety_Text_LookerThankYou
	speak LOCALID_CELEBISOCIETY_GRANDMA, DIR_WEST, Name_Grandma, Present_CelebiSociety_Text_GrandmaOfCourseDearie
	closemessage
	applymovement LOCALID_CELEBISOCIETY_GRANDMA, Present_CelebiSociety_Movement_GrandmaWalkToChair
	waitmovement 0
	setobjectxyperm LOCALID_CELEBISOCIETY_GRANDMA, 8, 5
	completequest QUEST_SAVE_ESTELLA
	setvar VAR_PLAY_LOOKER_SCENE_ON_TRANSITION, 1
	clearflag FLAG_ENTER_CELEBI_SOCIETY_FROM_QUEST
	clearflag FLAG_SYS_DISAPPEAR_QUESTS
	setflag FLAG_PLAY_LOOKER_ESTELLA_ON_TRANSITION
	releaseall
	end

Present_CelebiSociety_Movement_GrandmaWalkUp4:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Present_CelebiSociety_Movement_LookerWalkUp4:
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

Present_CelebiSociety_Movement_GrandmaWalkToChair:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Present_CelebiSociety_EventScript_Eldegoss::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ELDEGOSS, CRY_MODE_NORMAL
	msgbox Present_CelebiSociety_Text_Eldegoss, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

Present_CelebiSociety_Text_GrandmaDidYouMeetCelebi:
	.string "Here we are.\p"
	.string "To continue our conversation,\n"
	.string "did you truly meet Celebi?$"

Present_CelebiSociety_Text_LookerThatIsCorrect:
	.string "That is correct. We were sent\n"
	.string "to the past after being surrounded\l"
	.string "by a horde of wild Pokémon.$"

Present_CelebiSociety_Text_GrandmaThatIsIncredible:
	.string "How incredible…\p"
	.string "We here at the Celebi Society meet\n"
	.string "every month to clear the weeds and\l"
	.string "maintain the shrines.\p"
	.string "To think, Celebi is still out there…\p"
	.string "Such a thought brings peace to my soul.$"

Present_CelebiSociety_Text_LookerSoYouRevere:
	.string "So you in the city revere Celebi and\n"
	.string "Landorus, even to this day?$"

Present_CelebiSociety_Text_GrandmaIWish:
	.string "I wish that were the case.\p"
	.string "When the city became a major port, its\n"
	.string "people let go of the traditions set\l"
	.string "at Porta Bella's founding.\p"
	.string "We still maintain the oral traditions,\n"
	.string "but many of us are getting old…\p"
	.string "Only locals know of the importance of\n"
	.string "the spirits of Peace and Prosperity,\l"
	.string "but even still…\p"
	.string "Very few people have reverence for\n"
	.string "the spirits who gave Porta Bella its\l"
	.string "peaceful skies and fertile land…\p"
	.string "We fear these stories will die with\n"
	.string "us, only written in books as fables…$"

Present_CelebiSociety_Text_LookerThankYou:
	.string "Hmm…\p"
	.string "Thank you for sharing. I will need\n"
	.string "to think on this.$"

Present_CelebiSociety_Text_GrandmaOfCourseDearie:
	.string "Of course, dearie.\p"
	.string "If you would ever like to know more,\n"
	.string "I will gladly share what I've learned.$"

Present_CelebiSociety_Text_Eldegoss:
	.string "Ellllllldegoss!$"