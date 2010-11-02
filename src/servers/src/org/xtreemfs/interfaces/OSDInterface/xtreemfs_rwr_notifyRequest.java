package org.xtreemfs.interfaces.OSDInterface;

import java.io.StringWriter;
import org.xtreemfs.*;
import org.xtreemfs.foundation.buffer.ReusableBuffer;
import org.xtreemfs.foundation.oncrpc.utils.*;
import org.xtreemfs.interfaces.*;
import yidl.runtime.Marshaller;
import yidl.runtime.PrettyPrinter;
import yidl.runtime.Struct;
import yidl.runtime.Unmarshaller;




public class xtreemfs_rwr_notifyRequest extends org.xtreemfs.foundation.oncrpc.utils.Request
{
    public static final int TAG = 2010031291;

    public xtreemfs_rwr_notifyRequest() { file_credentials = new FileCredentials();  }
    public xtreemfs_rwr_notifyRequest( FileCredentials file_credentials, String file_id ) { this.file_credentials = file_credentials; this.file_id = file_id; }

    public FileCredentials getFile_credentials() { return file_credentials; }
    public String getFile_id() { return file_id; }
    public void setFile_credentials( FileCredentials file_credentials ) { this.file_credentials = file_credentials; }
    public void setFile_id( String file_id ) { this.file_id = file_id; }

    // java.lang.Object
    public String toString()
    {
        StringWriter string_writer = new StringWriter();
        string_writer.append(this.getClass().getCanonicalName());
        string_writer.append(" ");
        PrettyPrinter pretty_printer = new PrettyPrinter( string_writer );
        pretty_printer.writeStruct( "", this );
        return string_writer.toString();
    }

    // Request
    public Response createDefaultResponse() { return new xtreemfs_rwr_notifyResponse(); }

    // java.io.Serializable
    public static final long serialVersionUID = 2010031291;

    // yidl.runtime.Object
    public int getTag() { return 2010031291; }
    public String getTypeName() { return "org::xtreemfs::interfaces::OSDInterface::xtreemfs_rwr_notifyRequest"; }

    public int getXDRSize()
    {
        int my_size = 0;
        my_size += file_credentials.getXDRSize(); // file_credentials
        my_size += Integer.SIZE / 8 + ( file_id != null ? ( ( file_id.getBytes().length % 4 == 0 ) ? file_id.getBytes().length : ( file_id.getBytes().length + 4 - file_id.getBytes().length % 4 ) ) : 0 ); // file_id
        return my_size;
    }

    public void marshal( Marshaller marshaller )
    {
        marshaller.writeStruct( "file_credentials", file_credentials );
        marshaller.writeString( "file_id", file_id );
    }

    public void unmarshal( Unmarshaller unmarshaller )
    {
        file_credentials = new FileCredentials(); unmarshaller.readStruct( "file_credentials", file_credentials );
        file_id = unmarshaller.readString( "file_id" );
    }

    private FileCredentials file_credentials;
    private String file_id;
}