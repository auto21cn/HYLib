#include <ansi.h>
inherit NPC;

void create()
{
        set_name("叶翔",({"yexiang","ye"}));
        set("title",HIR"快活林"NOR);
        set("long","
叶翔本是个很英俊很坚强的人，全身都带着劲，带着逼人的锋芒，就好像
一把磨得雪亮的刀。但现在，刀已生锈，他英俊的脸上的肌肉已渐渐松驰、
渐渐下垂，眼睛已变得暗淡无光，肚子开始向外凸出，连声音都变得嘶哑
起来。\n");
        
        set("gender","男性");
        set("group","khlr");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "地契":         "高老大做梦都想得到快活林的地契。\n",
                "小蝶":         (: message_vision(CYN"叶翔拿起酒壶又喝了一口，眼中露出痛苦之色。\n"NOR,this_object()) :),
           ]));
        
        set("death_msg",CYN"\n$N缓缓道：“机会只有一次，错过了就永不再来，但每个人一生
中都至少会有这么样一次机会的。我求你，等机会来的时候，千万莫要错过。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance",1);
        set("chat_msg",({
                "叶翔苦笑道：“我也不知道为了什么，我只是忽然觉得很疲倦，疲倦得什么事
都不想去做，那种感觉你也许不会懂的。”\n",
                "他忽然笑了笑，道“高老大还肯让我喝这样的酒已经算很对得起我了，其实象
我这样的人现在只配喝马尿。”\n",
                "叶翔道“每个人，都有自己的命运，大多数人都在受着命运的摆布。只有很少
人能反抗、能改变自己的命运，我只恨我自己为什么不是这种人。”\n",
                "叶翔说：“你要记住，老伯是杀不死的！”\n",
        }) );                   
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}      
