---if don't have change quest icon system remove these and their related things in system ..
Questimportant = 1
QuestEvent = 2
QuestDaily = 3
Quests = {
    {
        NpcID = 100,
        MissionID = 100,
        Name = "Fantasy 01",
        InitDialog = "Fantasy Quest Test 01!",
        Daily = false,
        BeginConditions = {
            NoMission = {100},
            LvCheck_HigherThan = 65
        },
        ResultAction = {
            AddExp = {500000, 500000} -- Grants two experience rewards
        },
        Need = {
            Items = {
                {ID = 3457, Qty = 5}
            },
            Kills = {
                {ID = 103, Qty = 1}
            }
        },
        Rewards = {
            Items = {
                {ID = 9914, Qty = 1, Quality = 4} -- Mount Fragment
            },
            --Exp  = 500000,
            Money = 10000000,
            BagSpace = 3
        },
        GiveSelectedReward = true,
        HelpDialog = "Very helpful!",
        ResultDialog = "It seems like you're a true warrior! I'll gladly reward you."
    },
}
