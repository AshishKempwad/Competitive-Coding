    public int minMeetingRooms(int[][] intervals) {
        Map<Integer, Integer> m = new TreeMap<>();
        for (int[] t : intervals) {
            m.put(t[0], m.getOrDefault(t[0], 0) + 1);
            m.put(t[1], m.getOrDefault(t[1], 0) - 1);
        }
        int res = 0, cur = 0;
        for (int v : m.values()) {
            res = Math.max(res, cur += v);
        }
        return res;
    }



#################### c++ ##################

    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &t : intervals)
            m[t[0]]++, m[t[1]]--;
        int cur = 0, res = 0;
        for (auto &it : m)
            res = max(res, cur += it.second);
        return res;
    }

