 // copyright apstone, inc 1998
inherit NPC;

inherit F_DEALER;
void create()
{
        set_name("卖戒指的", ({ "ring seller" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                "一个普普通通的本地人，没有一点起眼的地方。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
// ring should be able to write something on it!!!!
        set("vendor_goods", ({
                __DIR__"obj/w_ring",
                __DIR__"obj/e_ring",
        }));
        set("chat_chance", 30);
        set("chat_msg", ({
                "卖戒指的道：看您春风满面，莫非有了意中人？\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        setup();
        carry_object(__DIR__"obj/kacloth")->wear();
} 
void init()
{
        object ob; 
        ::init();

        add_action("do_buy", "buy");add_action("do_list", "list");
} 

