#include <ansi.h>;
mixed names = ({
        ({
        "���ֹ㳡","����·","������","������Ϊ��","����������",
        "��΢��","����ƺ","������","������","ȫ��̴���", 
        "��ӹ��","������","��翷�ɽ��","������","���޺�", 
        "ѩɽ��ɽ��","һƷ�ô�Ժ","���ƺ���","��ָ��","��ָ��", 
        "��������","������","��������","���չ�¥","���ŷ�",
        "������","˿��֮·","��������","�ڷ��","���ŷ�",
        "�ϳ�","��Ҥ��","��Ȼ��","�ɹŲ�ԭ","Į��",
        "�ɹŲ�ԭ","���岿��","СϪ��","���ݸ�","���������",
        "������","���ݳ�","˿��֮·","���ݶ���","��ݮ��",
        "�����ַ�","ʮ�ֽ�ͷ","����������","������","ȫ��̴���",
        "�񶼾�¥","��ţ���","������","��گ�»���","������",
        "�����","���ƺ���","³����","ϲ�ݳ�","̫�ͽֿ�",
        "�����ھ�","�ų���","������","����ɽ����","��ˮ̶",
        "̫��","�����","������","��������","������",
        "������","ʥ����","�����ô���","�ɵµ�","ƽ����",
        "ɽ����","������","������","��������","������Ժ",
        "��̳��","��ȳ�","Ⱥ�ɹ�","������","ɯ��ƺ",
        "��ȸ����","³����","�׻�����","��������","�찲��",
        "�������","�����ھ�","�����","������","Ȫ������",
        "��������","�������","����¥","������","��ɽ����",                
        "�߹���","�����ַ�","��������","ϲ�ݳ�","��³��", 
        "����","ɽ����","����ͷ","��³��","��ɽ����",
        "����Ժ","ӿȪ��","������","���Ϸ�","�Ͻ��",
        "�ɷ��","����ɽ��","������","����̶","���ɷ�",                
        "��Ӧ��","�����","������Ժ","������","������", 
        }),
        ({
         "�α�","��å","ƫ��","�Խ�","����","�к�",
                 "С��","����",

        }),
        });
string ask_fangqi()
{
         object me;
object obj;
         me = this_player();
         if(me->query_condition("husong_busy")<=1)
         return "��û��������,������Ϲ����ʲ��?";
         me->clear_condition("husong_busy");
         me->add("combat_exp",-100+random(20));
         me->apply_condition("zzz_busy",4+random(4));
         me->delete_temp("hu_song");
if (obj=present("gong zi",environment(me)))
{
if(obj->query_temp("host")==me->query("id"))
{
destruct(obj);
}
}
         return "û��ϵ,�´μ���Ŭ�� ��";
}

string ask_job()
{     object wang,ob;
      object *team;
          int i=0,count=0,minexp,maxexp;
      string where;
          wang =this_object();
          ob=this_player();
          
  if (interactive(ob) && (int)ob->query_condition("zzz_busy"))  
       return "����²������ȵȻ�ɡ�";

  if (interactive(ob) && (int)ob->query_condition("guojob2_busy"))  
       return "�����ҿ�û�и�������񣬵Ȼ������ɡ�\n";

       if ((int)ob->query_condition("menpai_busy"))  
       return "�����Ǽ�Σ�չ������ҿ�"+ob->query("name")+"��Ҫ��Ϣһ�ᣡ\n";
//        if (ob->query_condition("husong_busy"))
//        return "������û�и��������";//husong busy time 
          
  if (interactive(ob) && ob->query_temp("hu_song")
      && (int)ob->query_condition("husong_busy"))  
       return "����һ�ε�����û���!";
          if(ob->query("combat_exp")<500000)
      return  "��Ĺ���̫���ˡ�";//too low exp
      team=ob->query_team();
      count=sizeof(team);
      if(count>=5)
          return "���²������"; //too many people
          minexp=ob->query("combat_exp");
          maxexp=minexp;
      
          for(i=1;i<count;i++)
      { if(team[i]!=0)
          {
                if(team[i]->query("combat_exp")<minexp)
            minexp=team[i]->query("combat_exp");
                if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
          }
          }
          if ((maxexp-minexp)>800000)
      return "���ǵ��书���̫���⡣";//exp too far
     //check ok
     // ob->set_temp("team_count",count);
          ob->apply_condition("husong_busy",30);
          for(i=0;i<count;i++)
          {if(team[i]!=0)
           team[i]->apply_condition("husong_busy",30);
           team[i]->set_temp("hu_song",1);
          }
          for(i=100;i*i*i/10<=maxexp;i++);
      where=names[0][random(120)];
          call_out("make_npc",0,i,ob,where,count);
          message_vision(HIY"\n$N�ӻ��֣�һλ���Ӵ������������˹�����\n"NOR,this_object());
          command("say ����Ұ���λ���ӻ��͵�"+where+"��");
          ob->set_temp("hu_song",1);
          ob->start_busy(2);
          return "��ȥ�ٻأ�һ·�϶��С�ġ�";   
}

void make_npc(int maxpot,object player,string where,int count)
{   object obj;
//        player->start_busy(3);
//      player->set("hu_song",1);
        player->set_temp("hu_song",1);
        obj = new(__DIR__"gongzi");
    obj->move(environment(player));
        obj->set_temp("target",where);
        obj->set_temp("maxpot",maxpot);
    obj->set_temp("count",count);
        obj->set_temp("host",player->query("id"));
        obj->set_leader(player);
        message_vision("$N��������$nһ���ж���\n",obj,player);
        obj->apply_condition("hu_song",200);
        return;

}    
