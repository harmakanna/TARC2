#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6 //check if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8  //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10   //buffers a quest name to gStringVar1

// quest number defines
#define QUEST_NONE  0xFFFF
#define QUEST_SAVE_ESTELLA          0 //Find Estella in the past - Done
#define QUEST_INVESTIGATE_PROSPERITY          1 // Investigate the abnormality at the Shrine of Prosperity - Done
#define QUEST_INTERROGATE_MATT          2 // Defeat Team Aqua - Done
#define QUEST_DEFEAT_PHOEBE          3 // Defeat Phoebe - Done
#define QUEST_FIND_THE_CULPRIT          4 // Defeat the correct gym challenger
#define QUEST_BONJOUR_EMMA          5 // Speak French to Emma - Done
#define QUEST_HELP_FISHERMAN          6 // Find the best fishing spot in town - Done
#define QUEST_EUREKA          7 // Find a battery to harness Mareep's power - Done
#define QUEST_GET_INTO_THE_GROOVE          8 // Find the idols scattered after the storm
#define QUEST_FARMLAND_INVASION_1         9 // Clear out the first wave of pest Pokemon
#define QUEST_FARMLAND_INVASION_2        10 // Clear out the second wave of pest Pokemon
#define QUEST_FARMLAND_INVASION_3        11 // Clear out the third wave of pest Pokemon
#define QUEST_FOREVER_FAITHFUL        12 // Defeat the hypnotized boyfriend
#define QUEST_SENTIMENTAL        13 // Find a heart scale in the past and bring it to the present - Done
#define QUEST_FIND_TASTY_MINT        14 // Find a tasty mint in the present and bring it back to the past
#define QUEST_SENT_TO_THE_FARM        15 // Find modern medicine for the ailing cows
#define QUEST_HOMEGROWN_REMEDIES        16 // Find herbal remedies lost to time for the ailing old man
#define QUEST_FORGOTTEN_TO_TIME        17 // Revive fossils - Done
#define QUEST_WITH_MUCH_GRATITUDE        18 // Send a thank you gift to Camilla from Estella
#define QUEST_20        19
#define QUEST_21        20
#define QUEST_22        21
#define QUEST_23        22
#define QUEST_24        23
#define QUEST_25        24
#define QUEST_26        25
#define QUEST_27        26
#define QUEST_I_MADE_THIS        27 // Defeat the devs!
#define QUEST_PARADOXICAL        28 // Defeat yourself!
#define QUEST_CATCH_GENIES        29 // Catch the genies - Done
#define QUEST_COUNT     (QUEST_CATCH_GENIES + 1)

#define SUB_QUEST_DEFEAT_GENIES 0

#define SUB_QUEST_DEFEAT_BLUE 1
#define SUB_QUEST_DEFEAT_MAY 2
#define SUB_QUEST_DEFEAT_COOLTRAINER 3
#define SUB_QUEST_DEFEAT_YOUNGSTER 4
#define SUB_QUEST_DEFEAT_LEAF 5

#define SUB_QUEST_CATCH_TORNADUS 6
#define SUB_QUEST_CATCH_THUNDURUS 7

#define QUEST_INVESTIGATE_PROSPERITY_SUB_COUNT 1
#define QUEST_FIND_THE_CULPRIT_SUB_COUNT 5
#define QUEST_CATCH_GENIES_SUB_COUNT 2
#define SUB_QUEST_COUNT (QUEST_INVESTIGATE_PROSPERITY_SUB_COUNT + QUEST_FIND_THE_CULPRIT_SUB_COUNT + QUEST_CATCH_GENIES_SUB_COUNT)

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
