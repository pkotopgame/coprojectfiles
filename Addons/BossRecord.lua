print("Loading Boss Knowledge NPC")
PKO = {}
PKO.CharInfo = {}
local fp = assert(io.open(GetResPath('CharacterInfo.txt')))
for line in fp:lines() do
	local position = string.find(line, '[ \t]*//')
	if position ~= 1 then
		local Column	= split(line, '\t')
		local CharID	= tonumber(Column[1])
		local CharName	= tostring(Column[2])
		local CharLV	= Column[61]
		local MXHP		= tonumber(Column[62])
		local MXSP		= tonumber(Column[64])
		local MNATK		= tonumber(Column[66])
		local MXATK		= tonumber(Column[67])
		local Resist	= tonumber(Column[68])
		local Defense	= tonumber(Column[69])
		local Hitrate	= tonumber(Column[70])
		local Dodge		= tonumber(Column[71])
		local HpRec		= tonumber(Column[74])
		local SpRec		= tonumber(Column[75])
		local MSDP		= tonumber(Column[79])
		local CharEXP	= tonumber(Column[91])
		if(PKO.CharInfo[CharID] == nil)then
			PKO.CharInfo[CharID] = {
				ID		= CharID,	
				Name	= CharName, 
				HP		= MXHP,		
				SP		= MXSP,		
				MIN		= MNATK,		
				MAX		= MXATK,		
				PR		= Resist,	
				DEF		= Defense,	
				HR		= Hitrate,	
				FLEE	= Dodge,	
				HREC	= HpRec,		
				SREC	= SpRec,		
				MS		= MSDP,
				LV		= CharLV, 	
				EXP   	= CharEXP
			}
		end
	end
end

-- ----------------
-- Table Index's
-- ----------------
RespawnTime = {}
BossToRecord = {}
RecordBoss = {}
BossLocations = {}

BossLocations[805] = "Skeletar Island (282,173)" -- Example location
BossLocations[678 ] = "Demoonic World 2 (239,249)" -- Example location
BossLocations[679] = "Demoonic World 1 (239, 249)" -- Example location
BossLocations[757 ] = "Phoenix Island (94,240)" -- Example location
BossLocations[786] = "Phoenix Island (121,307)" -- Example location
BossLocations[776] = "Silver Mine (23,14)" -- Example location
BossLocations[788] = "Silver Mine (131,74)" -- Example location
BossLocations[74] = "Abandon Mine 1 (112,94)" -- Example location
BossLocations[1008] = "Silver Mine (80,96)" -- Example location
BossLocations[1007] = "Silver Mine (95,16)" -- Example location
BossLocations[1009] = "Silver Mine (15,133)" -- Example location
BossLocations[974] = "Abaddon 5 (72,64)" -- Example location
BossLocations[975] = "Abaddon 5 (191,64)" -- Example location
BossLocations[976] = "Abaddon 5 (190,179)" -- Example location
BossLocations[977] = "Abaddon 5 (72,179)" -- Example location
BossLocations[1001] = "Abaddon 5 (2575,82)" -- Example location
BossLocations[979] = "Abaddon 10 (73,182)" -- Example location
BossLocations[980] = "Abaddon 10 (73,64)" -- Example location
BossLocations[981] = "Abaddon 10 (189,64)" -- Example location
BossLocations[982] = "Abaddon 10 (311,181)" -- Example location
BossLocations[983] = "Abaddon 10 (311,181)" -- Example location
BossLocations[984] = "Abaddon 10 (311,303)" -- Example location
BossLocations[985] = "Abaddon 10 (190,303)" -- Example location
BossLocations[986] = "Abaddon 10 (69,303)" -- Example location
BossLocations[987] = "Abaddon 18 (56,56)" -- Example location
BossLocations[988] = "Eternal Abaddon (202,105)" -- Example location
BossLocations[789] = "Black Dragon Lair" -- Example location
BossLocations[1105] = "1st Aurora Area (187,102)" -- Example location
BossLocations[1113] = "1st Dark Area (252,459)" -- Example location
BossLocations[1117] = "Morpheus Abyss Demon (252,459)" -- Example location
BossLocations[1109] = "2nd Aurora Area (187,102)" -- Example location
BossLocations[1836] = "Chaos Glacier" -- Example location

BossLocations[1839] = "Chaos Spring" -- Example location
BossLocations[1840] = "Chaos Dream" -- Example location
BossLocations[1841] = "Chaos Desert" -- Example location
BossLocations[1842] = "Chaos Argent" -- Example location
BossLocations[1843] = "Chaos Icicle" -- Example location
BossLocations[1844] = "Snow War" -- Example location


-- ----------------
-- Bosses IDS
-- ----------------
RecordBoss[1] = 805
RecordBoss[2] = 678 
RecordBoss[3] = 679
RecordBoss[4] = 757 
RecordBoss[5] = 786
RecordBoss[6] = 776
RecordBoss[7] = 788
RecordBoss[8] = 74
RecordBoss[9] = 1008
RecordBoss[10] = 1007
RecordBoss[11] = 1009
RecordBoss[12] = 974 
RecordBoss[13] = 975
RecordBoss[14] = 976
RecordBoss[15] = 977
RecordBoss[16] = 1001
RecordBoss[17] = 979
RecordBoss[18] = 980
RecordBoss[19] = 981
RecordBoss[20] = 982
RecordBoss[21] = 983
RecordBoss[22] = 984
RecordBoss[23] = 985
RecordBoss[24] = 986
RecordBoss[25] = 987
RecordBoss[26] = 988
RecordBoss[27] = 789
RecordBoss[28] = 1105
RecordBoss[29] = 1113
RecordBoss[30] = 1117
RecordBoss[31] = 1109
RecordBoss[31] = 1836
RecordBoss[32] = 1839
RecordBoss[33] = 1840
RecordBoss[34] = 1841
RecordBoss[35] = 1842
RecordBoss[36] = 1843
RecordBoss[37] = 1844
-- --------------------
-- Bosses Respawn Time
-- --------------------
RespawnTime[805] = 10800 
RespawnTime[678] = 10800
RespawnTime[679] = 10800 
RespawnTime[757] = 10800
RespawnTime[786] = 10800 
RespawnTime[776] = 10800 
RespawnTime[788] = 10800 
RespawnTime[74] = 10800 
RespawnTime[1008] = 10800 
RespawnTime[1007] = 10800 
RespawnTime[1009] = 10800
RespawnTime[974] = 14400 
RespawnTime[975] = 14400 
RespawnTime[976] = 14400 
RespawnTime[977] = 14400 
RespawnTime[1001] = 14400
RespawnTime[979] = 14400 
RespawnTime[980] = 14400 
RespawnTime[981] = 14400 
RespawnTime[982] = 14400 
RespawnTime[983] = 14400 
RespawnTime[984] = 14400 
RespawnTime[985] = 14400 
RespawnTime[986] = 14400 
RespawnTime[987] = 14400 
RespawnTime[988] = 14400 
RespawnTime[789] = 21600 
RespawnTime[1105] = 14400 
RespawnTime[1113] = 14400 
RespawnTime[1117] = 14400 
RespawnTime[1109] = 14400 
RespawnTime[1836] = 14400 
RespawnTime[1839] = 21600 
RespawnTime[1840] = 14400 
RespawnTime[1841] = 14400 
RespawnTime[1842] = 14400 
RespawnTime[1843] = 14400 
RespawnTime[1844] = 14400 
--
-- ----------------------------
-- Record tables for monsters
-- ----------------------------
for i,v in pairs (RecordBoss) do
	BossToRecord[v] = true
end

-- ---------------------------
-- CHECK STATUS
-- ---------------------------

function CheckBossRespawn(id)
	if file_exists(GetResPath("../PlayerData/Boss/"..""..id..".txt")) == false then
		table.save({LastKilled = 0 , RecordRespawn = 0 },GetResPath("../PlayerData/Boss/"..""..id..".txt"),"a")
	end
	local Boss = table.load(GetResPath("../PlayerData/Boss/"..""..id..".txt"),"r")
	if Boss.RecordRespawn >= 1 then
		local RemainingTime = Boss.RecordRespawn - os.time()
		if RemainingTime <= 0 then
			Boss.LastKilled = 0
			Boss.RecordRespawn = 0
			table.save(Boss,GetResPath("../PlayerData/Boss/"..""..id..".txt"),"w")
		end
		local dead = "Dead"
		local respawn = ""..GetTime(RemainingTime)..""
		return dead,respawn
	end
	if Boss.RecordRespawn == 0 then
		local alive = "Alive"
		local notice = "00:00:00"
		return alive,notice
	end
end

-- ---------------------------
-- CHECK LAST KILLER
-- ---------------------------
function LastKillBossName(id)
	if file_exists(GetResPath("../PlayerData/Boss/"..""..id..".txt")) == false then
		table.save({LastKilled = 0 , RecordRespawn = 0 },GetResPath("../PlayerData/Boss/"..""..id..".txt"),"a")
	end
	local Boss = table.load(GetResPath("../PlayerData/Boss/"..""..id..".txt"),"r")
	if Boss.LastKilled == 0 then
		killer = "Nobody"
	else
		killer = Boss.LastKilled
	end
	return killer
end		

-- ----------------------------
-- NPC Function
-- ----------------------------
function BossRecord()
	Talk(1,"Dean: What I do for a living is to get news for Phoenix Island Radio. I'm monitoring bosses here in Ascaron and let others know the latest update about them.")
	local count = 0
	local page = 1
	for i,v in pairs(RecordBoss)do
		print(PKO.CharInfo[v].Name)
		Text(page, PKO.CharInfo[v].Name, MonsterStatus,v)
		count = count + 1
		if( (count/6) == math.floor(count/6) )then
			Text(page,">> Next Page",JumpPage,page + 1)
			if count > 6 then
				Text(page,"<< Back Page",JumpPage,page - 1)
			end
			page = page + 1
			Talk(page,"Dean: I hope you can find what you are looking for!")
		end
		if i == table.getn(RecordBoss) then
			Text(page,"<< Back Page",JumpPage,page - 1)
			Text(page,"Close Page",CloseTalk)
		end
	end
end

-- ---------------------------
-- LOADING STATUS
-- ---------------------------
function MonsterStatus(Player, Boss)
    local MobID = GetChaID(Boss)
    local Status, Notice = CheckBossRespawn(Boss)
    local Killer = LastKillBossName(Boss)
    local Message = nil
    Message = AdjustTextSpace(">> "..GetMonsterName(Boss).." Status <<", 40, "_")
    Message = Message..AdjustTextSpace("Health Status:", 7)..AdjustTextSpace(Status, 24, "_")
    Message = Message..AdjustTextSpace("Last Killer:", 7)..AdjustTextSpace(Killer, 29, "_")
    Message = Message..AdjustTextSpace("Respawn Time:", 7)..AdjustTextSpace(Notice, 30, "_")
    Message = Message..AdjustTextSpace("Location:", 7)..AdjustTextSpace(BossLocations[Boss] or "Unknown", 30, "_") -- Add location
    Message = Message..AdjustTextSpace("HP:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].HP, 30, "_")
    Message = Message..AdjustTextSpace("SP:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].SP, 30, "_")
    Message = Message..AdjustTextSpace("Minimum Damage:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].MIN, 12, "_")
    Message = Message..AdjustTextSpace("Maximum Damage:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].MAX, 12, "_")
    Message = Message..AdjustTextSpace("Physical Resist:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].PR, 10, "_")
    Message = Message..AdjustTextSpace("Defense:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].DEF, 25, "_")
    Message = Message..AdjustTextSpace("Hitrate:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].HR, 25, "_")
    Message = Message..AdjustTextSpace("Dodge:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].FLEE, 25, "_")
    Message = Message..AdjustTextSpace("HP Recovery:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].HREC, 17, "_")
    Message = Message..AdjustTextSpace("SP Recovery:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].SREC, 17, "_")
    Message = Message..AdjustTextSpace("Movement Speed:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].MS, 12, "_")
    Message = Message..AdjustTextSpace("Level:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].LV, 25, "_")
    Message = Message..AdjustTextSpace("Experience:", 7)..AdjustTextSpace(PKO.CharInfo[Boss].EXP, 20, "_")
    HelpInfoX(Player, 0, Message)
end


-- ---------------------------
-- PLAYER KILL BOSS HOOK maybe something in function get hp -0 then it bug
-- ---------------------------
function RecordKilledBosses(Ignore, Dead, Player)
    local GetKillerName = GetChaDefaultName(Player)
    local GetBossName = GetChaDefaultName(Dead)
    local GetBossID = GetChaID(Dead)
    local GuildID = GetChaGuildID(Player)
    local GuildName = "N/A"

    if GuildID ~= 0 then
        GuildName = GetGuildName(GuildID)
    end

    if BossToRecord[GetBossID] == true then
        local Boss = {}
        if(file_exists(GetResPath("../PlayerData/Boss/"..GetBossID..".txt")) ~= false) then
            local Boss = table.load(GetResPath("../PlayerData/Boss/"..GetBossID..".txt"), "r")
        end
        local respawn = RespawnTime[GetBossID]
        Boss.RecordRespawn = os.time() + respawn
        Boss.LastKilled = GetKillerName
        table.save(Boss, GetResPath("../PlayerData/Boss/"..GetBossID..".txt"), "w")
		
		local BossLocation = BossLocations[GetBossID] or "Unknown Location"

       ScrollNotice("<Phoenix Island Report> "..GetBossName.." has been slain by "..GetKillerName.." Guild Name: ["..GuildName.."] in ".. BossLocation.." with a time of "..os.date('%H:%M:%S'), 1, 0xFFF6E58D)
    end
end

Hook:AddPostHook("GetExp_PKM", RecordKilledBosses)