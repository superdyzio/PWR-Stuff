class KalkulatorGrawitacji {
        public static void main(String[] argumenty) {
                double stalaGrawitacji = 9.81; //przyspieszenie ziemskie m/s^2
                double predkoscPocz = 10.0;
                double czasSpadania = 10.0;
                double drogaPocz = 10.0;
                double drogaKonc = stalaGrawitacji*czasSpadania*czasSpadania/2+predkoscPocz*czasSpadania+drogaPocz;
                System.out.println("Droga przebyta przez ciało po "
                        + czasSpadania + " sekundach to " + drogaKonc + " m.");
        }
}
