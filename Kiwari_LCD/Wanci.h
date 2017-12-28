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

