import "@/app/ui/global.css";
import {inter} from "@/app/ui/fonts";

//Layout.tsx (typescript) is the file that determines the styles of the entire web application

export default function RootLayout({
  children,
}: {
  children: React.ReactNode;
}) {
  return (
    <html lang="en">
      {/* <body>{children}</body>  change to the one below. antialiased is a Tailwind addon that smooths out the font*/} 
      <body className={`${inter.className} antialiased`}>{children}</body>
    </html>
  );
}
