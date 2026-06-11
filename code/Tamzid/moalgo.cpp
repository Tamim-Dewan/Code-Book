 struct MO
 {
     struct node
     {
         ll id, left, right;
     };
  
     vector<node> queries;
     vector<ll> val, cnt;
     vector<ll> ans;
  
     ll num, questions, block;
  
     void build(vector<ll> &vec, vector<pair<ll, ll>> &q)
     {
         num = vec.size();
         val.resize(num + 1);
  
         block = sqrt(num);
         // 1-based indexing
         for (ll i = 1; i <= num; i++)
             val[i] = vec[i - 1];
  
         questions = q.size();
         queries.resize(questions);
         ans.resize(questions);
  
  
         cnt = vec;
         sort(cnt.begin(), cnt.end());
         cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());
         map<ll, ll> mp;
         for (ll i = 0; i < cnt.size(); i++)
             mp[cnt[i]] = i;
  
         for (ll i = 1; i <= num; i++)
             val[i] = mp[val[i]];
  
         cnt.clear();
         cnt.resize(mp.size());
  
         
  
         for (ll i = 0; i < questions; i++)
         {
             queries[i].id = i;
             queries[i].left = q[i].first;
             queries[i].right = q[i].second;
         }
  
         sort(queries.begin(), queries.end(), [&](node one, node two)
              {
                  ll start1 = one.left / block, start2 = two.left / block;
                  ll end1 = one.right / block, end2 = two.right / block;
      
                  if(start1==start2)return end1<end2;
                  return start1<start2; });
     }
  
     ll times = 0;
  
     void add(ll ind)
     {
         if (!cnt[ind])
             times++;
  
         cnt[ind]++;
     }
  
     void del(ll ind)
     {
         if (cnt[ind] == 1)
             times--;
  
         cnt[ind]--;
     }
  
     vector<ll> getresult()
     {
         
         ll start = 1, end = 1;
         add(val[1]);
  
         for (ll i = 0; i < questions; i++)
         {
             ll left = queries[i].left, right = queries[i].right;
  
             while (end < right)
                 add(val[++end]);
             while (start > left)
                 add(val[--start]);
  
             while (end > right)
                 del(val[end--]);
             while (start < left)
                 del(val[start++]);
  
             ans[queries[i].id] = times;
         }
  
         return ans;
     }
 };
