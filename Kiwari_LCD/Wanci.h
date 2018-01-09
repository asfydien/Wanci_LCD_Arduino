char* poe[] = {"Ahad", "Senen", "Salasa", "Rebo", "Kemis", "Jumaah", "Saptu"};

String pepereneian_waktu[] = {"00:00 Tengah Peuting", // 00.00-01.00
                              "01:00 Janari Gede", // 01.00-03.00
                              "03:30 Janari Leutik", // 03.30-4.30
                              "04:30 Balebat", // waktu fajar geus udat-udat belah wetan (04.30-05.00)
                              "05:00 Carancang Tihang", // geus liwat fajar, waktu tetenjoan masih remeng-remeng (05.00)
                              "07:00 Haneut Moyan", // waktu ngeunah-ngeunahna dipake moyan (07.00-08.30)
                              "09:00 Rumangsang", // panon poe geus karasa panas (09.00)
                              "10:00 Pecat Sawed", // waktu munding anu dipake ngawaluku sawah dilaan (dipecat) sawedna (10.00)
                              "12:00 Manceran", // panon poe aya luhureun sirah (12.00)
                              "13:00 Lingsir Ngulon", // panon poe geus mimiti ngageser ka Beulah kulon (13.00)
                              "15:00 Panon Poe Satangtung", // 15.00
                              "16:00 Tunggang Gunung", // panon poe mimiti surup dina luhureun gunung (16.00-17.00)
                              "17:00 Sariak Layung", // layung cahaya panon poe katenjo burahay beureum (17.00-18.00)
                              "18:30 Sareupna", // geus mimiti reup poek (18.30)
                              "20:00 Sareupna Budak" // waktu budak leutik geus carapeeun ulin jeung ngaji (20.00)
};

String pepereneian_waktu24[] = {"01:00 Tumorek", // tidak mendengar apa-apa, artinya waktu orang pada umumnya tertidur pulas kira-kira sekitar jam 01.00
                                "02:00 Janari Leutik", // dini hari kecil (awal) kira-kira sekitar jam 02.00
                                "03:00 Janari Gede", // dini hari besar (akhir) kira-kira sekitar jam 03.00
                                "04:00 Kongkorongok Hayam", // ayam berkokok kira-kira sekitar jam 04.00
                                "05:00 Balebat", // fajar kira-kira sekitar jam 05.00
                                "06:00 Carangcang Tihang", // hari mulai Terang kira-kira sekitar jam 06.00
                                "07:00 Meletek Panonpoe", // munculnya matahari kira-kira sekitar jam 07.00
                                "08:00 Ngaluluh Taneuh", // menggarap Tanah (petani pergi berladang mengolah tanah) kira-kira sekitar jam 08.00
                                "09:00 Haneut Moyan", // berjemur saat sinar Matahari sedang hangat kira-kira sekitar jam 09.00
                                "10:00 Rumangsang", // sinar matahari mulai panas kira-kira sekitar jam 10.00
                                "11:00 Pecat Sawed", // pada saat itu petani melepaskan tali kerbau agar kerbau bisa mencari makan sendiri kira-kira sekitar jam 11.00
                                "12:00 Tangange", // tengah hari kira-kira sekitar jam 12.00
                                "13:00 Lingsir", // matahari bergerak ke arah barat kira-kira sekitar jam 13.00
                                "14:00 Kalangkang Satangtung", // bayangan setinggi badan (panjang bayangan sama dengan tinggi tubuh) kira-kira sekitar jam 14.00
                                "15:00 Mengok", // matahari sudah mulai condong ke arah barat kira-kira sekitar jam 15.00
                                "16:00 Tunggang Gunung", // matahari sudah berada di atas puncak gunung kira-kira sekitar jam 16.00
                                "17:00 Sariak Layung", // matahari sudah mulai tenggelam menyisakan lembayung kira-kira sekitar jam 17.00
                                "18:00 Sareupna", // matahari tenggelam / hari sudah mulai gelap kira-kira sekitar jam 18.00
                                "19:00 Harieum Beungeut", // sinar matahari sudah tidak tampak dan hari sudah benar-benar gelap kira-kira sekitar jam 19.00
                                "20:00 Sareureuh Budak", // anak-anak pada waktu ini biasanya sudah tertidur kira-kira sekitar jam 20.00
                                "21:00 Tumoke", // waktu ketika suara binatang Toke sudah mulai terdengar kira-kira sekitar jam 21.00
                                "22:00 Sareureuh Kolot", // waktu ketika orang tua / dewasa sudah tertidur kira-kira sekitar jam 22.00
                                "23:00 Indung Peuting", // mega hideung = bulan sudah tepat diatas mega hitam sudah muncul kira-kira sekitar jam 23.00
                                "24:00 Tengah Peuting", // tengah malam kira-kira sekitar jam 24.00
                               };

String get_peperenian_waktu(unsigned int jam, unsigned int menit){ 
   unsigned int j,m;

   for (int n=1; n++; n<14){
      j = pepereneian_waktu[n].substring(0,2).toInt();
      m = pepereneian_waktu[n].substring(3,5).toInt();
   
      if ( (jam*100+menit) <= (j*100+m) ) {
          return pepereneian_waktu[n-1].substring(6);
        break;
      }
      
   }
   
   return "";
   
}

String get_poe(int d){
   if (d<6)
      return poe[d];

   return "";
}

