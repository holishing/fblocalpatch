--- src/mainframe.cpp	2016-02-16 20:31:52.000000000 +0800
+++ src/mainframe.cpp2	2018-07-18 00:25:52.412313000 +0800
@@ -187,7 +187,7 @@
 	LoadIcons();
 
 
-	gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX "VERSION );
+	gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX " VERSION );
 
 	m_pNotebook = new CNotebook();
 	gtk_notebook_set_scrollable(GTK_NOTEBOOK(m_pNotebook->m_Widget), TRUE);
@@ -285,9 +285,9 @@
 		url = url.substr(first, last - first + 1);
 
 	/* Remove telnet:// from url */
-	first = url.find_first_not_of("telnet://");
-	if (first != string::npos)
-		url.erase(0, first);
+	const string telnetPrefix = "telnet://";
+	if(url.substr(0, telnetPrefix.size()) == telnetPrefix)
+		url.erase(0, telnetPrefix.size());
 
 	if ( site == NULL )
 		site = &AppConfig.m_DefaultSite;
@@ -1677,7 +1677,7 @@
 	m_pView = view;
 	if( !m_pView || !m_pView->GetCon() )
 	{
-		gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX "VERSION );
+		gtk_window_set_title (GTK_WINDOW (m_Widget), "PCManX " VERSION );
 		gtk_entry_set_text( GTK_ENTRY(m_URLEntry), "");
 		return;
 	}
@@ -1690,7 +1690,7 @@
 	if( ! con->IsClosed() )
 		m_pNotebook->SetPageTitle( m_pView, title );
 
-	title += " - PCManX "VERSION;
+	title += " - PCManX " VERSION;
 	gtk_window_set_title (GTK_WINDOW (m_Widget), title.c_str() );
 
 	char time_str[100];
